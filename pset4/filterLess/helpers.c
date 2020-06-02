#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0); // finding the average grey shade
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average; // assigning the average gray shade to each color
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // formula to get the sepia shade
            int sepiaRed = round(image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189);
            if (sepiaRed > 255) // returning the 255 for red if turned out larger than 255
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168);
            if (sepiaGreen > 255)// returning the 255 for green if turned out larger than 255
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131);
            if (sepiaBlue > 255)// returning the 255 for blue if turned out larger than 255
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed; // assigning the values
            image[i][j].rgbtGreen = sepiaGreen; // assigning the values
            image[i][j].rgbtBlue = sepiaBlue; // assigning the values

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; // creating temp file to store the row before converting
    for (int i = 0; i < height; i++)
    {
        for (int t = 0; t < width; t++)
        {
            temp[i][t] = image[i][width - 1 - t]; // storing the converted row
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j]; // assigning temp pixels to image pixels
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; // creating a temp file
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j]; // copying image to temp file
        }
    }
    for (int i = 0; i < height; i++) // i loop for height of the image
    {
        for (int j = 0; j < width; j++) // j loop for width of the image
        {
            int pixel_count = 0; // devider wheter it's 4, 6 or 9
            float blurRed = 0;
            float blurGreen = 0;
            float blurBlue = 0;
            for (int p = -1; p < 2; p++)
            {
                for (int z = -1; z < 2; z++)
                {
                    if (i + p >= 0 && i + p <= height - 1 && j + z >= 0 && j + z <= width - 1) // uhh... don't ask
                    {
                        pixel_count++ ;
                        blurRed = blurRed + temp[i + p][j + z].rgbtRed;
                        blurGreen = blurGreen + temp[i + p][j + z].rgbtGreen;
                        blurBlue = blurBlue + temp[i + p][j + z].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtRed = round(blurRed / pixel_count); // yay. assigning the result to image
            image[i][j].rgbtGreen = round(blurGreen / pixel_count); // yay. assigning the result to image
            image[i][j].rgbtBlue = round(blurBlue / pixel_count); // yay. assigning the result to image
        }
    }
    return;
}
