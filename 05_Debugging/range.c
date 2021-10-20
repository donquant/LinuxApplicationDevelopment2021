#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SYNTAX_ERR "SyntaxError: range arguments must be represented as integers, for example as 73 or -101"

const char help[] = "\nusage: range arg1 [ arg2 arg3 ]\n\n" 
                    "range returns a sequence of integers from start (inclusive) to stop (exclusive) by step.\n"
                    "range i j produces\n"
                    "i\n"
                    "i+1\n"
                    "...\n"
                    "j-1.\n"
                    "start defaults to 0, and stop is omitted!\n"  
                    "range 3 produces\n" 
                    "0\n"
                    "1\n"
                    "2.\n";

int parse(const char * string){

    int len = strlen(string);
    int i;
    for(i = 0; i < len; i++){
        if(i == 0){
            if(!(string[i] == '-' || string[i] == '+' || isdigit(string[i]))){
                puts(SYNTAX_ERR);
                exit(EXIT_FAILURE);
            }
        }
        else{
            if(!isdigit(string[i])){
                puts(SYNTAX_ERR);
                exit(EXIT_FAILURE);
            }
        }
    }
    return atoi(string);    
}

int main(int argc, char **argv){
    
    if(argc == 1)
        puts(help);
    else if(argc == 2){
        int stop = parse(argv[1]);
        int i;
        for(i = 0; i < stop; i++)
            printf("%d\n", i); 
    }else if(argc == 3){
        int start = parse(argv[1]);
        int stop  = parse(argv[2]);
        int i;
        for(i = start; i < stop; i++)
            printf("%d\n", i); 
    }else if(argc == 4){
        int start = parse(argv[1]);
        int stop  = parse(argv[2]);
        int step  = parse(argv[3]);
        if (step == 0){
            puts("ValueError: range arg3 must not be zero");
            exit(EXIT_FAILURE);
        }
        int i;
        if (start > stop && step < 0)
            for(i = start; i > stop; i += step)
                printf("%d\n", i);
        else if (start < stop && step > 0) 
            for(i = start; i < stop; i += step)
                printf("%d\n", i);
    }else{
        puts("SyntaxError: more than 3 arguments were given");
        puts(help);
        exit(EXIT_FAILURE);
    }
    return 0;
}
