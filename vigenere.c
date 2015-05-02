/**
* vigenere.c
*
* Jacob Sherman
* jacob@jbsherman.com
*
* encrypts plain text using Vigenere encryption
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
        printf("try again!\n");
        return 1;
    }
else
    {
    // check argv is all alpha
    int keyLength = strlen(argv[1]);
    for (int ctr = 0; ctr < keyLength; ctr++)
    {
        if(isalpha(argv[1][ctr]) == false)
        {
            printf("You must enter only alphabetical letters! \n");
            return 1;
        }
    }
    string keyWord = argv[1];
    
    // get plain text message from user
    string plainText = GetString();
    
    //  encryption begins below  
    int keyIndex = 0; 
    int j = 0;
    for (int counter = 0, messageLength = strlen(plainText); counter < messageLength; counter++)
        {
            if (isalpha(plainText[counter]))
            {
                keyIndex = j % keyLength;
                j++;
                if (islower(plainText[counter]))
                    {
                    if islower(keyWord[keyIndex])
                        {
                        printf("%c", (((plainText[counter] - 97) + (keyWord[keyIndex]-97)  ) % 26) + 97);
                        }
                     else 
                        {
                        printf("%c", (((plainText[counter] - 97) + (keyWord[keyIndex]-65)  ) % 26) + 97);
                        }
                    }
                else   // plaintext char is Capitalized
                    {
                    if islower(keyWord[keyIndex])
                    {
                        printf("%c", (((plainText[counter] - 65) + (keyWord[keyIndex]-97)  ) % 26) + 65);
                    }
                     else   // keyWord char also Capital
                        {
                        printf("%c", (((plainText[counter] - 65) + (keyWord[keyIndex]-65)  ) % 26) + 65);
                        }
                    }
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
 
