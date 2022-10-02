#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//to check the arguemenet count and save the array of strings
int main(int argc, string argv[])
{
    if (argc == 2) //validation check to see if there is 2 commmand line arguements
    {
        if (strlen(argv[1]) == 26) //check if the key is of the apropriate length
        {
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                for (int j = i + 1; j < strlen(argv[1]) + 1; j++)
                {
                    //check if the key has no repetitive values
                    if (tolower(argv[1][i]) != tolower(argv[1][j]))
                    {
                    }
                    else
                    {
                        printf("no repetitve letters\n");
                        return 1;
                    }
                }
            }
            for (int a = 0; a < strlen(argv[1]); a++)
            {
                // validation check to see the key has alphabets only
                if (isalpha(argv[1][a]) != 0)
                {
                }
                else
                {
                    printf("alphabets only\n");
                    return 1;
                }
            }
        }
        else
        {
            printf("enter 26 letters\n");
            return 1;
        }
        //prompt the user for the text to decipher
        string user = get_string("plaintext:  ");
        for (int d = 0; d < strlen(user); d++)
        {
            // the following commands is implemented to make sure the lowercase and uppercase letter remains same
            if (isupper(user[d]) != 0)
            {
                user[d] = toupper(argv[1][user[d] - 65]);
            }
            else if (islower(user[d]) != 0)
            {
                user[d] = tolower(argv[1][user[d] - 97]);
            }
        }
        //output the ciphered text
        printf("ciphertext: %s", user);
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage ./substitution key\n");
        return 1;
    }
}