//C program to create a right-aligned pyramid of blocks similar to those seen in Nintendo’s Super Mario Brothers Mario, where Mario must ascend the pyramid.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do //do-while loop urges user to input a number between 1-8, inclusive
    {
        height = get_int("Height: "); //Asks user for height of pyramid
    }
    while (height < 1 || height > 8);
    
    for (int i = 1; i <= height; i++) //Loop to make sure the total number of spaces and hashes on each line are not more than 8
    {
        for (int j = 0; j < (height - i); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
