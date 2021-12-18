/**
 * @file guess.c
 * @author donquant
 * @brief a prpgram guessing a number from 0 to 100
 * @version 1.0
 * 
 * Usage: guess [OPTIONS]
 *
 * -i, --info     Give multilingual help list
 * -r, --roman    Use roman numerals
 * -?, --help     Give this help list
 *     --usage    Give a short usage message
 * -V, --version  Print program version
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdlib.h>
#include <argp.h>
#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(string) gettext(string)
#ifndef LOCALEDIR
#define LOCALEDIR "."
#endif

const char *argp_program_version = "guess 1.0";
const char *argp_program_bug_address = "<dasurfspot@gmail.com>";

/* Program documentation. */
static char doc[] = "guess - a program guessing number from 0 to 100";

/* The options we understand. */
static struct argp_option options[] = {
    {"info",  'i', 0, 0, "Give multilingual help list"},
    {"roman", 'r', 0, 0, "Use roman numerals"},
    { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments {
    int info, roman;
};

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state) {
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key) {
    
        case 'r':
            arguments->roman = 1;
            break;
        case 'i':
            arguments->info = 1;
            break;

        case ARGP_KEY_ARG:
            if (state->arg_num > 0)
                /* Too many arguments. */
                argp_usage (state);
            break;

        case ARGP_KEY_END:
            if (state->arg_num > 0)
                /* Not enough arguments. */
                argp_usage (state);
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
/* Our argp parser. */
static struct argp argp = {options, parse_opt, 0, doc};
/* Array of roman numbers */
static char *roman101[] = {"N", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", 
                            "XI", "XII", "XIII","XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", 
                            "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", 
                            "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL", 
                            "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", 
                            "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", 
                            "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
                            "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX", 
                            "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII","LXXXIX", "XC",
                            "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"};
/**
 * @brief function to convert an integer @p n to number in Roman representation
 * 
 * @param n integer
 * @return number in Roman representation
 */
char * roman_num (int n) {
    return roman101[n];
}  

int main (int argc, char ** argv) {
    
    setlocale (LC_ALL, "");
    bindtextdomain ("guess", LOCALEDIR);
	textdomain ("guess");
    
    struct arguments arguments;
    arguments.roman = 0;
    arguments.info  = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    if(arguments.info) {
    
        printf(_("Usage: guess [OPTION...]\n"
                 "guess - a program guessing number from 0 to 100\n\n"
                 "  -i, --info                 Give multilingual help list\n"
                 "  -r, --roman                Use roman numerals\n"
                 "  -?, --help                 Give this help list\n"
                 "      --usage                Give a short usage message\n"
                 "  -V, --version              Print program version\n\n"));
        return 0;
        
    }
    //printf("Roman = %s\n", arguments.roman ? "yes" : "no");
    
    int lower = 0;
    int upper = 100;
    int diff, half;
    char input;

    printf(_("Select an integer from %d to %d\n"), lower, upper);

    while(1) {

        if((diff = upper - lower) == 0) {
            if(arguments.roman)
                printf(_("Your integer is %s\n"), roman_num(upper));
            else
                printf(_("Your integer is %d\n"), upper);
            return 0;
        }
        half = diff / 2;  
    
        if(arguments.roman)
            printf(_("Is your integer bigger than %s ?\n"), roman_num(lower + half));
        else
            printf(_("Is your integer bigger than %d ?\n"), lower + half);
        
        input = getchar();

        if (input == 'y') {

            if (diff == 1) {
                
                if(arguments.roman)
                    printf(_("Your integer is %s\n"), roman_num(upper));
                else
                    printf(_("Your integer is %d\n"), upper);
                return 0;

            } else { 
                
                lower += half + 1; 

            }
        }

        else if (input == 'n') {
            
            if (diff == 1) {
                
                if(arguments.roman)
                    printf(_("Your integer is %s\n"), roman_num(upper));
                else
                    printf(_("Your integer is %d\n"), upper);
                return 0;

            } else 
                
                upper = lower + half;

        } else
            
            printf(_("Program recognizes only y or n as input\n"));

        while (getchar() != '\n')
            continue;

    }    
}
