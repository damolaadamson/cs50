// C program that encrypts messages using Caesar’s cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++) // Checks if all the characters in the string are digits
        {
            if ((argv[1][i]) < 47 || argv[1][i] > 58)
            {
                printf("Usage: %s key\n", argv[0]); // Indicates user did not enter appropriate string on command line
                exit(1); // Ends the program if a character is not a digit
            }
        }
        
        int k = atoi(argv[1]); // Converts string to integer if all characters are digits
        string p = get_string("plaintext: "); // Asks user for the text to encrypt
        printf("ciphertext: ");
        for (int j = 0; j < strlen(p); j++)
        {
            if (islower(p[j]))
            {
                printf("%c", ((p[j] - 97 + k) % 26) + 97); // Changes lowercase alphabet to another lowercase alphabet 'k' places away
            }
            else if (isupper(p[j]))
            {
                printf("%c", ((p[j] - 65 + k) % 26) + 65); // Changes uppercase alphabet to another uppercase alphabet 'k' places away
            }
            else
            {
                printf("%c", p[j]); // Prints characters that are not alphabet as they are
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: %s key\n", argv[0]); // Indicates user did not enter required number of strings on command line
        exit(1);
    }
}
