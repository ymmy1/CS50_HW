#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    unsigned char bytes[512];
    int img_count = 0;
    FILE *out = NULL;
    char filename[4];

    while (true)
    {
        // read a block of the memory card image
        int block = fread(bytes, sizeof(char), 512, f);

        // break out of the loop when we reach the end of the card image
        if (feof(f))
        {
            fclose(out);
            break;
        }
        // check if we found a JPEG
        bool jpgFound = bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0;

        // if we found a yet another JPEG, we must close the previous file
        if (jpgFound == true && img_count > 0)
        {
            fclose(out);
        }
        // if we found a JPEG, we need to open the file for writing
        if (jpgFound == true)
        {
            sprintf(filename, "%03i.jpg", img_count);
            out = fopen(filename, "w");
            img_count++;
        }

        // write anytime we have an open file
        if (img_count > 0)
        {
            fwrite(bytes, sizeof(char), block, out);
        }

    }

    fclose(f);
    return 0;


}
