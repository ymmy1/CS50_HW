#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text;
    int letterNumber = 0;
    float wordNumber = 1;
    int sentenceNumber = 0;
    string n;
    int i;
    float L;
    float S;

    text = get_string("Enter Your Text: "); /* Asking user for text */
    int length = strlen(text);

    for (i = 0; i < length ; i++) /* Word count loop, jumping from char to char */
    {
        char letter = text[i]; 
        char spacePunct = text[i];
        char space = text[i - 1];
        int punct = text[i];


        int letterResult = isalpha(letter); /* check if char is a letter */
        int spaceResult = isspace(space); /* check if  char is a space*/
        int spacePunctResult = ispunct(spacePunct); /* check if char is a symbol */

        if (letterResult != 0)
        {

            letterNumber++;

        }
        /* do not count 2 spaces in a row, or a space and symbol as 2 words */
        if ((spaceResult != 0 && letterResult != 0) || (spaceResult != 0 && spacePunctResult != 0)) 
        {
            wordNumber++;

        }
        if (punct == 33 || punct == 63 || punct == 46) /* "!", "?" and "." symbol check */
        {
            sentenceNumber++;
        }
    }
    
    /* Formula time */
    float avgNumber = 100 / wordNumber;
    L = avgNumber * letterNumber;
    S = avgNumber * sentenceNumber;

    float index = round((0.0588 * L) - (0.296 * S) - 15.8);

    /* Output time */
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.f\n", index);
    }

}