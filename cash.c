// A C program that implements a greedy algorithm and asks the user how much change is owed
// before printing the minimum number of coins with which that change can be made.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int i = 0;
    int cents;

    do
    {
        dollars = get_float("Change owed: "); //Asks user to enter change owed in dollars
    }
    while (dollars < 0);

    cents = round(dollars * 100); //Converts the dollar amount to cents 
    
    while (cents >= 25) //While loops to decide which coin value to subtract from the change
    {
        cents -= 25;
        i++; //Increments and stores the number of times the while loop runs
    }
    while (cents >= 10)
    {
        cents -= 10;
        i++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        i++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        i++;
    }

    printf("Coins: %i\n", i); // Prints out the total number of coins required
}
