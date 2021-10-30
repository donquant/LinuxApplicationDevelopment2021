#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#define BUFFER_SIZE 512
#define IWR "Incomplete write"

int main(int argc, char *argv[]){
  
    if (argc == 3){
        
        int infile, outfile;
        infile = open(argv[1], O_RDONLY);
        if(infile == -1){
            fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
        outfile = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if(outfile == -1){
            fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
            exit(EXIT_FAILURE);
        } 

        char buf[BUFFER_SIZE];
        size_t bytes_read;
        size_t bytes_wrote;
        while ((bytes_read = read(infile, buf, BUFFER_SIZE)) > 0){
            if(bytes_read == -1){
                fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
                exit(EXIT_FAILURE);
            }
            bytes_wrote = write(outfile, &buf, bytes_read);
            if(bytes_wrote == - 1){
                fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
                exit(EXIT_FAILURE);
            } else if(bytes_wrote != bytes_read){
                fprintf(stderr, "errno = _: %s\n" , IWR);
                exit(EXIT_FAILURE);
            }
        }

        int close_status, unlink_status;
        close_status = close(infile);
        if(close_status == - 1){
            fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
        close_status = close(outfile);
        if(close_status == - 1){
            fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
        unlink_status = unlink(argv[1]);
        if(unlink_status == - 1){
            fprintf(stderr, "errno = %i: %s\n" , errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    return 0;  
}
