#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int s = get_int("s: ");
    int c = get_int("c: ");

    if (s == c)
    {
        printf("Same\n");
        printf("s: %p\n", &s);
        printf("c: %p\n", &c);
    }
    else
    {
        printf("Different\n");
        printf("s: %p\n", &s);
        printf("c: %p\n", &c);
    }
}