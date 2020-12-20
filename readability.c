// C program that computes the approximate grade level needed to comprehend some text.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float L = 0, S = 0;
    int W = 1, index;
    string text = get_string("Text: "); // Asks user to enter a text

    for (int i = 0; i < strlen(text); i++)
    {
        if (((65 <= text[i]) && (text[i] <= 90)) || ((97 <= text[i]) && (text[i] <= 122))) // Condition for counting the number of letters
        {
            L++;
        }
        else if (text[i] == 32) // Condition for counting the number of words using spaces
        {
            W++;
        }
        else if (text[i] == 46 || text[i] == 33 || text[i] == 63) // Condiition for counting the number of sentences
        {
            S++;
        }
    }
    printf("%.0f Letter(s)\n", L);
    printf("%i Word(s)\n", W);
    printf("%.0f Sentence(s)\n", S);
    
    L = ((L / W) * 100);
    S = ((S / W) * 100);
    index = round(0.0588 * L - 0.296 * S - 15.8); // Calculates the grade and rounds to the nearest integer
    
    if (index < 1)
    { 
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
