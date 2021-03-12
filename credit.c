// A C program that asks the user for a credit or debit card number then uses Luhn's Algorithm to determine if the
// number is valid and letting the user know if it is an American Express, Mastercard, or Visa card number.

#include <stdio.h>
#include <cs50.h>

int length_card_number(long card_number);
int checksum(long card_number);

int main(void)
{
    long card_number;
    int sum;
    do
    {
        card_number = get_long("Number: "); //Asks user for their card number
    }
    while (card_number <= 0);
    
    int length = length_card_number(card_number); //Finds the number of digits in the credit card number
    if (checksum(card_number) == 0 && (length == 13 || length == 15 || length == 16))
    {
        if (card_number >= 340000000000000 && card_number < 350000000000000)
        {
            printf("AMEX\n");
        }
        else if (card_number >= 370000000000000 && card_number < 380000000000000)
        {
            printf("AMEX\n");
        }
        else if (card_number >= 5100000000000000 && card_number < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if (card_number >= 4000000000000 && card_number < 5000000000000)
        {
            printf("VISA\n");
        }
        else if (card_number >= 4000000000000000 &&  card_number < 5000000000000000)
        {
            printf("VISA\n");
        }
        else
        {
        printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int length_card_number(long card_number) 
{
    int i;
    for (i = 0; card_number != 0; i++)
    {
        card_number /= 10; //Counts the number of digits in the card number by dividing by 10 until it gets to 0
    }
    return i;
}

int checksum(long card_number) //Function to check Luna's Algorithm
{
    int sum = 0;
    {
        for (int j = 0; card_number != 0; j++)
        {
            if (j % 2 == 0) //Sums every other digit in the card number starting from the last
            {
                sum += card_number % 10;
                card_number /= 10; 
            }
            else //Multiplies the digits that were not added by 2 and adds the products’ digits
            {
                int digit = 2 * (card_number % 10);
                sum += (digit / 10) + (digit % 10);
                card_number /= 10;
            }
        }
    }
    
    return sum % 10;
}
