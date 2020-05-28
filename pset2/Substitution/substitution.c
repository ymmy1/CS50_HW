#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[]) /* Stage 1 */
{
    int i;
    int j = 0;
    string stringKey = argv[1];
    char totalKey[26] = "";
    if (argc == 2) /* Veryfying number of argc */
    {
        for (i = 0; i < strlen(stringKey); i++) /* converting each letter to uppercase */
        {
            char keyTest = toupper(stringKey[i]);
            int alpha = isalpha(keyTest);
            if (alpha != 0) /* Veryfying argc all letters */
            {
                if (strlen(stringKey) == 26) /* Veryfying number of letters 26 */
                {
                    for (j = 0; j < strlen(totalKey); j++) /* Scaning for repetitive letters */
                    {
                        if (keyTest != totalKey[j])
                        {
                            j++;
                        }
                        else
                        {
                            printf("Key must not contain repeated characters\n");
                            return 1;
                        }
                    }
                    strncat(totalKey, &keyTest, 1); /* Converting complete */
                }
                else
                {
                    printf("Key must contain 26 characters\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must only contain alphabetic character\n");
                return 1;
            }
        }
    }
    else /* break if there are more than 1 key value */
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string userText = get_string("plaintext:  "); /* Stage 2 */
    printf("ciphertext: ");
    
    for (i = 0; i < strlen(userText); i++) /* main user text letter check formula */
    {
        char textLetterTest = userText[i];
        int letAlpha = isalpha(textLetterTest);
        
        if (letAlpha != 0) /* if char is a letter doing next */
        {
            int uAlpha = 0;
            int p = 0;
            int c = 0;
            char textUpperLetterTest = userText[i];
            uAlpha = isupper(textUpperLetterTest);
            
            if (uAlpha != 0) /* if char is uppercase doing next */
            {
                p = userText[i] - 65;
                c = totalKey[p];
                printf("%c", c);
            }
            else /* if char is not uppercase */
            {
                p = userText[i] - 97;
                c = tolower(totalKey[p]);
                printf("%c", c);
            }
        }
        else /* if char is not a letter */
        {
            printf("%c", textLetterTest);
        }
    }
    printf("\n");
    return 0;
}