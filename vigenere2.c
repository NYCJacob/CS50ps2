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
else
    {
    // check arguement is all alpha
    int keyLength = strlen(argv[1]);
    for (int ctr = 0; ctr < keyLength; ctr++)
    {
        if(isalpha(argv[1][ctr]) == false)
            return 1;
    }
    string keyWord = argv[1];
    
    // get plain text message from user
    printf("\nEnter plain text: ");
    string plainText = GetString();
    
    //  encryption begins below   
    for (int counter = 0, j=0, messageLength = strlen(plainText); counter < messageLength; counter++)
        {
            if (isalpha(plainText[counter]))
            {
                j = counter % strlen(keyWord);
                if (islower(plainText[counter]))
                {
                    printf("%i:", plainText[counter] + keyWord[j]);
                    printf("%c:", (((plainText[counter] -97)+ keyWord[j])%26) + 97);
                    printf("\n");
                }
                else
                  printf("%c", (((plainText[counter] - 65)+ keyWord[j])%26) + 65);
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
