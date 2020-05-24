#include <cs50.h>
#include <stdio.h>


int main(void)
/* Asking user for a height */
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    /* The while rule */
    while (n < 1 || n > 8);
    /* Number of rows */
    for (int i = 0; i < n; i++)
    {
        /* Number of left spaces */
        for (int x = i; x < n - 1; x++)
        {
            printf(" ");
            
        }
        /* Number of left hashtags */
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        /* Number of middle spaces */
        for (int s = 0; s < 2; s++)
        {
            printf(" ");
        }
        /* Number of right hashtags */
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");    
    }
    
}
