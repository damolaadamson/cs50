#include <stdio.h>
#include <cs50.h>

int checksum(long number); //Allows main code to be placed above created function

int main(void)
{
    int sum;
    long number;
    
    do
    {
        number = get_long("Card Number: "); //Asks user for their card number
    }
    while (number <= 0);
    
    sum = checksum(number); //Uses the checksum function created below
    
    if (number >= 340000000000000 && number < 350000000000000 && sum == 0)
    {
        printf("AMEX\n");
    }
    else if (number >= 370000000000000 && number < 380000000000000 && sum == 0)
    {
        printf("AMEX\n");
    }
    else if (number >= 5100000000000000 && number < 5600000000000000 && sum == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (number >= 4000000000000 && number < 5000000000000 && sum == 0)
    {
        printf("VISA\n");
    }
    else if (number >= 4000000000000000 &&  number < 5000000000000000 && sum == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



int checksum(long number) //Function to check Luhn's algorithm
{
    long digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8;
    long modulo, digit9, digit10, digit11, digit12, digit13, digit14, digit15, digit16;
    int sum, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
    
    //Step to select an individual digit from the card number
    digit1 = ((number % 100) - (number % 10)) / 10;
    digit2 = ((number % 10000) - (number % 1000)) / 1000;
    digit3 = ((number % 1000000) - (number % 100000)) / 100000;
    digit4 = ((number % 100000000) - (number % 10000000)) / 10000000;
    digit5 = ((number % 10000000000) - (number % 1000000000)) / 1000000000;
    digit6 = ((number % 1000000000000) - (number % 100000000000)) / 100000000000;
    digit7 = ((number % 100000000000000) - (number % 10000000000000)) / 10000000000000;
    digit8 = ((number % 10000000000000000) - (number % 1000000000000000)) / 1000000000000000;
    
    digit9 = (number % 10);
    digit10 = ((number % 1000) - (number % 100)) / 100;
    digit11 = ((number % 100000) - (number % 10000)) / 10000;
    digit12 = ((number % 10000000) - (number % 1000000)) / 1000000;
    digit13 = ((number % 1000000000) - (number % 100000000)) / 100000000;
    digit14 = ((number % 100000000000) - (number % 10000000000)) / 10000000000;
    digit15 = ((number % 10000000000000) - (number % 1000000000000)) / 1000000000000;
    digit16 = ((number % 1000000000000000) - (number % 100000000000000)) / 100000000000000;
    
    //Multiplies individual digit by 2
    digit1 *= 2;
    digit2 *= 2;
    digit3 *= 2;
    digit4 *= 2;
    digit5 *= 2;
    digit6 *= 2;
    digit7 *= 2;
    digit8 *= 2;
    
    //Gets the products' digits 
    while (digit1 != 0)
    {
        modulo = digit1 % 10; //Finds the remainder after dividing the product by 10
        sum1 += modulo; //Adds the remainder to the sum and stores it
        digit1 /= 10; // Divides the digit by 10 and stores the value (It will repeat the loop until digit1 = 0)
    }
    while (digit2 != 0)
    {
        modulo = digit2 % 10;
        sum2 += modulo;
        digit2 /= 10;
    }
    while (digit3 != 0)
    {
        modulo = digit3 % 10;
        sum3 += modulo;
        digit3 /= 10;
    }
    while (digit4 != 0)
    {
        modulo = digit4 % 10;
        sum4 += modulo;
        digit4 /= 10;
    }
    while (digit5 != 0)
    {
        modulo = digit5 % 10;
        sum5 += modulo;
        digit5 /= 10;
    }
    while (digit6 != 0)
    {
        modulo = digit6 % 10;
        sum6 += modulo;
        digit6 /= 10;
    }
    while (digit7 != 0)
    {
        modulo = digit7 % 10;
        sum7 += modulo;
        digit7 /= 10;
    }
    while (digit8 != 0)
    {
        modulo = digit8 % 10;
        sum8 += modulo;
        digit8 /= 10;
    }
    
    sum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8; //Sum of the individual digits of the products
    sum = sum + digit9 + digit10 + digit11 + digit12 + digit13 + digit14 + digit15 + digit16;
    sum = sum % 10;
    return sum; // Returns the modulo of the sum of the products and the numbers that were not multiplied by 2
}
