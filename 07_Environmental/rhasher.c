#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <rhash.h>
#include "config.h"

#ifdef HAVE_LIBREADLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

size_t receiveLine(char** line);
int getHash(const char* input, char* output, int crypto, int base);

int main(void) {
	
    rhash_library_init();
	char* line = NULL;
	ssize_t line_len;
	char output[130];	
	while ((line_len = receiveLine(&line)) > 1) {
	
    	const char* crypto_name = strtok(line, " ");
		int crypto;
        int output_base;
        size_t input_len;
        int hash_out;

        /* Select crypto algorithm */
		if (strcasecmp(crypto_name, "tth") == 0) {
			crypto = RHASH_TTH;
		} else if (strcasecmp(crypto_name, "sha1") == 0) {
			crypto = RHASH_SHA1;
		} else if (strcasecmp(crypto_name, "md5") == 0) {
			crypto = RHASH_MD5;
		} else {
			printf("Unrecognized command: %s\n", crypto_name);
			continue;
		}

		/* Select output */
		output_base = (isupper(crypto_name[0])) ? RHPR_HEX : RHPR_BASE64 ;

        /* hash computation and printing */
		char* input = strtok(NULL, " ");
		input_len = strlen(input);
		if (input[input_len - 1] == '\n')
			input[input_len - 1] = '\0';
		hash_out = getHash(input, output, crypto, output_base);
		if (hash_out >= 0)
			printf("%s\n", output);
	}
	free(line);
}

size_t receiveLine(char** line) {
#ifdef HAVE_LIBREADLINE
    free(*line);
    size_t len_of_line;
    char* check;
    if (isatty(STDIN_FILENO)) {
    	check = "$ ";
    	rl_outstream = stdout;
    } else {
    	check = NULL;
    	rl_outstream = stderr;
    }
    *line = readline(check);
	if (*line == NULL) return 0;
    add_history(*line);
    len_of_line = strlen(*line);
    return len_of_line;
#else
	size_t n;
	return getline(line, &n, stdin);
#endif
}

int getHash(const char* input, char* output, int crypto, int base) {

	int res;
	char digest[64];
	if (input[0] == '"') {
        input++; 
		res = rhash_msg(crypto, input, strlen(input), digest);
		if (res < 0) {
			fprintf(stderr, "Error: unsuccesfull attempt of hash computation\n");
			return res;
		}
	} else { 
		res = rhash_file(crypto, input, digest);
		if (res < 0) {
			fprintf(stderr, "Error: %s\n", strerror(errno));
			return res;
		}
	}
	rhash_print_bytes(output, digest, rhash_get_digest_size(crypto), base);
	return 0;
}
