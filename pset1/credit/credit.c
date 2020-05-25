/* linking libraries */
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long int n;
    int m;
    double j;
    double r;
    long int i;
    int total;
    do
    {
        n = get_long("Card Number: ");
    }
    while (n < 1);
    /* getting every second number */
    for (i = 100; i < n * 10; i = i * 100)
    {
        r = n % i;
        r = floor(r / i * 10) * 2; /* multiply each digit by 2*/
        j = j + floor(r / 10);
        m = r ;
        j = j + m % 10;
    }
    /* adding the sum to the sum of not multipied digits*/
    for (i = 10; i < n * 10; i = i * 100)
    {
        r = n % i;
        r = floor(r / i * 10);
        j = j + r;
    }
    total = j;
    /* finding the right card */
    if (total % 10 == 0) /*Sum Validation check */
    {
        /* VISA check*/
        if (n >= 1000000000000000 && (floor(n / 1000000000000000)) == 4)
        {
            printf("VISA\n");
        }
        else if (n >= 1000000000000 && (floor(n / 1000000000000)) == 4)
        {
            printf("VISA\n");
        }
        /* AMEX check*/
        else if (n >= 100000000000000 && (floor(n / 10000000000000)) == 34)
        {
            printf("AMEX\n");
        }
        else if (n >= 100000000000000 && (floor(n / 10000000000000)) == 37)
        {
            printf("AMEX\n");
        }
        /* MASTERCARD check*/
        else if (n >= 1000000000000000 && (floor(n / 100000000000000)) == 51)
        {
            printf("MASTERCARD\n");
        }
        else if (n >= 1000000000000000 && (floor(n / 100000000000000)) == 52)
        {
            printf("MASTERCARDn");
        }
        else if (n >= 1000000000000000 && (floor(n / 100000000000000)) == 53)
        {
            printf("MASTERCARD\n");
        }
        else if (n >= 1000000000000000 && (floor(n / 100000000000000)) == 54)
        {
            printf("MASTERCARD\n");
        }
        else if (n >= 1000000000000000 && (floor(n / 100000000000000)) == 55)
        {
            printf("MASTERCARD\n");
        }
        /* Card type check failed*/
        else
        {
            printf("INVALID\n");
        }
    }
    /* Card Validation Failed */
    else
    {
        printf("INVALID\n");
    }



   
}
