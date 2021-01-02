//C program that implements a substitution cipher in which the key must contain 26 unrepeated letters

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int check_repetition(char *key); //Allows main code to be placed above created function

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26) //Checks if command line argument has a key with 26 characters
    {
        string key = argv[1];
        if (check_repetition(key) == -1) //Checks if key contains repeated characters
        {
            for (int i = 0; i < strlen(key); i++) //Checks if all characters in key are alphabets
            {
                if (isalpha(key[i]))
                {
                    continue;
                }
                else
                {
                    printf("Key must contain only alphabets\n");
                    exit(1);
                }
            }

            string p = get_string("plaintext: "); //Prompts user for the text to encrypt
            printf("ciphertext: "); //Prints encrypted text

            for (int j = 0; j < strlen(p); j++) 
            {
                if (islower(p[j])) //Checks for lowercase alphabets
                {
                    printf("%c", tolower(key[p[j] - 97])); //Makes sure lowercase alphabets remain lowercase
                }
                else if (isupper(p[j])) //Checks for uppercase alphabets 
                {
                    printf("%c", toupper(key[p[j] - 65])); //Makes sure uppercase alphabets remain uppercase
                }
                else
                {
                    printf("%c", p[j]); //Makes sure non-alphabetical characters are unchanged
                }
            }
            printf("\n");
        }
        else
        {
            printf("Key cannot contain repeated alphabets\n");
            exit(1);
        }
    }
    else
    {
        printf("Key must contain only one command-line argument with 26 alphabets\n");
        exit(1);
    }
}

int check_repetition(char *key) //Function to check for repeated characters
{
    int m = -1; //Declared value in case there is no repetition
    for (int k = 0; k < strlen(key); k++) //Stores the character to be checked
    {
        for (int l = k + 1; l < strlen(key); l++) //Loop to scan through rest of key for repetition of stored character
        {
            if (key[k] == key[l])
            {
                m = k; //Returns position of repetition occurence
                break;
            }
        }
        if (m != -1) 
        {
            break;
        }
    }
    return m;
}
