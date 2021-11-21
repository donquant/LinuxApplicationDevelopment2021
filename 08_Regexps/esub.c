#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

void err_malloc(char **arr,  int n) { 
        
        *arr = malloc(n * sizeof(char*));
        if (*arr == NULL){
            puts("Error: unsuccessful attempt of memory allocation!");
            exit(EXIT_FAILURE);
        }

}

void print_match(int start, int end, char *str) {
    for (int i = start; i < end; i++) {
        fputc(str[i], stdout);
    }
}

int main(int argc, char ** argv) {

    if(argc < 3){
        fprintf(stderr, "usage: %s regexp substitution string\n", argv[0]);
        exit(EXIT_FAILURE);    
    }

    char* re  = argv[1];
    char* sub = argv[2];
    char* str = argv[3];
    char* err;

    regex_t regex;
    size_t n;
    int res;
    int esc = 0;
    size_t pid;

    /* 
     *  int regncomp(regex_t *restrict preg, const char *restrict pattern, size_t len, int cflags);
     *  
     *  When successful, regcomp() returns 0 and fills in the structure pointed to by preg.
     *  One member of that structure (other than re_endp) is publicized: re_nsub, of type size_t, 
     *  contains the number of parenthesized subexpressions within the RE (except that the value of 
     *  this member is undefined if the REG_NOSUB flag was used).
     *
     */

    if ((res = regcomp(&regex, re, REG_EXTENDED))) {

        size_t size = regerror(res, &regex, (char*) NULL, (size_t) 0); /* size of error string */
        err_malloc(&err, size);
        regerror(res, &regex, err, size);
        fprintf(stderr, "%s: %s\n", re, err);
        free(err);
        exit(EXIT_FAILURE);

    }
    
    n = regex.re_nsub;
    regmatch_t m[n];

    /*
     * int regexec(const regex_t *restrict preg, const char *restrict string, 
     *             size_t nmatch, regmatch_t pmatch[restrict], int eflags);
     *
     * The regexec() function matches the compiled RE pointed to by preg against the string, 
     * subject to the flags in eflags, and reports results using nmatch, pmatch, and the returned value.  
     *
     */


    /* no match - return original str */
    if ((res = regexec(&regex, str, n + 1, m, 0)) == REG_NOMATCH) {
   
        puts(str);
        return 0;
   
    }
    /* some other error */
    if (res) {

        size_t size = regerror(res, &regex, (char*) NULL, (size_t) 0); /* size of error string */
        err_malloc(&err, size);
        regerror(res, &regex, err, size);
        fprintf(stderr, "%s: %s\n", re, err);
        free(err);
        exit(EXIT_FAILURE);

    }

    /* first pass - error check */
    for (char *s = sub; *s != '\0'; s++) {
        
        /* escape sequence */
        if (*s == '\\' && !esc) {
          
            esc = 1;
        
        /* pocket match */
        } else if (isdigit(*s) && esc) {

            pid = s[0] - '0';
            if (pid > n) {
                fprintf(stderr, "error: \"%s\": \\%zu not defined in RE\n", re, pid);
                exit(EXIT_FAILURE);    
            }
            esc = 0;

        /* other cases */
        } else {
          
            if (esc)
                esc = 0; 
                
        }
    }

    if (esc) {
            
        fprintf(stderr, "error: \"%s\": unterminated substitute in regular expression\n", sub);
        exit(EXIT_FAILURE);    
    
    }
   
    /* second pass - print */
     
    for (int i = 0; i < m[0].rm_so; i++) {
        fputc(str[i], stdout);
    }

    for (char *s = sub; *s != '\0'; s++) {
        
        /* escape sequence */
        if (*s == '\\' && !esc) {
          
            esc = 1;
        
        /* pocket match */
        } else if (isdigit(*s) && esc) {

            pid = s[0] - '0';
            if(pid)
                print_match(m[pid].rm_so, m[pid].rm_eo, str);
            else
                fputc(*s, stdout);
            esc = 0;

        /* other cases */
        } else {
          
            if (esc)
                esc = 0; 
           fputc(*s, stdout);
                
        }
    }
       
    for (unsigned long i = m[0].rm_eo; i < strlen(str); i++) {
        fputc(str[i], stdout);
    }
    
    puts("");
    regfree(&regex);

    return 0;
}
