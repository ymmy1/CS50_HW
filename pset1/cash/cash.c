/* linking libraries */
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float n;
    int coins = 0;
    do
    {
        n = round(get_float("Change owed: ") * 100);
    }
    /* while rule */
    /* changed n < 0 to n < 1 to avoid bugs with 0.001 input */ 
    while (n < 1);
    /* finding the number of 25c coins */
    for (int i = 25; i <= n;)
    {
        n = n - i;
        coins++;
    }
    /* finding the number of 10c coins */
    for (int z = 10; z <= n;)
    {
        n = n - z;
        coins++;
    }
    /* finding the number of 5c coins */
    for (int x = 5; x <= n;)
    {
        n = n - x;
        coins++;
    }
    /* finding the number of 1c coins */
    for (int y = 1; y <= n;)
    {
        n = n - y;
        coins++;
    }
    /* printing the total of coins */
    printf("%i\n", coins);
    /* making sure we do not owe anything */
    printf("Change owed: %.2f\n", n);
}
