#include <stdio.h>
#include <locale.h>
#include "libintl.h"

#define _(string) gettext(string)

int main (void) {

    setlocale(LC_ALL, "");
	bindtextdomain("ru", ".");
	textdomain("ru");
    
    int lower = 0;
    int upper = 100;
    int diff, half;
    char input;

    printf(_("Select an integer from %d to %d\n"), lower, upper);

    while(1) {

        if((diff = upper - lower) == 0) {
            printf(_("Your integer is %d\n"), upper);
            return 0;
        }
        half = diff / 2;  

        printf(_("Is your integer bigger then %d ?\n"), lower + half);
        //printf("lower = %d\nupper = %d\n", lower, upper);
        
        input = getchar();

        if (input == 'y') {

            if (diff == 1) {
                
                printf(_("Your integer is %d\n"), upper);
                return 0;

            } else { 
                
                lower += half + 1; 

            }
        }

        else if (input == 'n') {
            
            if (diff == 1) {
                
                printf(_("Your integer is %d\n"), lower);
                return 0;

            } else 
                
                upper = lower + half;

        } else
            
            printf(_("Program recognizes only y or n as input\n"));

        while (getchar() != '\n')
            continue;

    }    
}
