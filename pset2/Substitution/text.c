    string userText = get_string("plaintext:  ");
    printf("ciphertext: ");
    
    for (i = 0; i < strlen(userText); i++) /* main letter check formula */
    {
        char textLetterTest = userText[i];
        int letAlpha = isalpha(textLetterTest);
        
        if (letAlpha != 0) /* if char is a letter going next */
        {
            int uAlpha = 0;
            int p = 0;
            int c = 0;
            char textUpperLetterTest = userText[i];
            uAlpha = isupper(textUpperLetterTest);
            
            if (uAlpha != 0) /* if char is uppercase going next */
            {
                p = userText[i] - 65;
                c = ((p + key) % 26) + 65;
                printf("%c", c);
            }
            else /* if char is not uppercase */
            {
                p = userText[i] - 97;
                c = ((p + key) % 26) + 97;
                printf("%c", c);
            }
        }
        else /* if char is not a letter */
        {
            printf("%c", textLetterTest);
        }
    }
        printf("\nwe good\n"); /* finish, by the way the check did not notice this printf */
    return 0;