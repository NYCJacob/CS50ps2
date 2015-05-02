/**
* caesar.c
*
* Jacob Sherman
* jacob@jbsherman.com
*
* encrypts plain text using Ceasar encryption
*/


#include <ctype.h>   // contains isalpha and others
#include <stdlib.h>   // contains atoi declaration
#include <cs50.h>
#include <stdio.h>
#include <string.h>  // contains strlen
#include <ctype.h>   // contains isalpha etc


int main(int argc, string argv[])
{
if ( argc != 2)
    {
        printf("You must enter one but no more than one integar arguement- try again!\n");
        return 1;
    }
    //  spec says can assume user only types integars
else
    {
    //  convert string input to int type needed even assuming user types a number
    int k = atoi(argv[1]);
    
    // get plain text message from user
    string plainText = GetString();
    //  encryption begins below
    
    for (int counter = 0, messageLength = strlen(plainText); counter < messageLength; counter++)
        {
            if (isalpha(plainText[counter]))
            {
                if (islower(plainText[counter]))
                    printf("%c", (((plainText[counter] - 97)+k)%26) + 97);
                else
                  printf("%c", (((plainText[counter] - 65)+k)%26) + 65);
            }
            else
            {
                printf("%c",  plainText[counter]);
            }
        
        }  // end for loop
        printf("\n");
    }  // end argc else 
 return 0;
}  // end main
