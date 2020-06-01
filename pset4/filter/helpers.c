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


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            int gxRed = 0;
            int gxGreen = 0;
            int gxBlue = 0;

            int gyRed = 0;
            int gyGreen = 0;
            int gyBlue = 0;

            for (int p = -1; p < 2; p++)
            {
                for (int z = -1; z < 2; z++)
                {
                    if (i + p >= 0 && i + p <= height - 1 && j + z >= 0 && j + z <= width - 1) // ignoring value of 0 beyond the border
                    {
                        if (p == 0)
                        {
                            gxRed = gxRed + (temp[i + p][j + z].rgbtRed * (z * 2));
                            gxGreen = gxGreen + (temp[i + p][j + z].rgbtGreen * (z * 2));
                            gxBlue = gxBlue + (temp[i + p][j + z].rgbtBlue * (z * 2));
                        }

                        else
                        {
                            gxRed = gxRed + (temp[i + p][j + z].rgbtRed * z);
                            gxGreen = gxGreen + (temp[i + p][j + z].rgbtGreen * z);
                            gxBlue = gxBlue + (temp[i + p][j + z].rgbtBlue * z);
                        }
                        if (z == 0)
                        {
                            gyRed = gyRed + (temp[i + p][j + z].rgbtRed * (p * 2));
                            gyGreen = gyGreen + (temp[i + p][j + z].rgbtGreen * (p * 2));
                            gyBlue = gyBlue + (temp[i + p][j + z].rgbtBlue * (p * 2));
                        }
                        else
                        {
                            gyRed = gyRed + (temp[i + p][j + z].rgbtRed * p);
                            gyGreen = gyGreen + (temp[i + p][j + z].rgbtGreen * p);
                            gyBlue = gyBlue + (temp[i + p][j + z].rgbtBlue * p);
                        }
                    }
                }
            }
            // rounding square root of squared Gx and squared Gy for all colors
            int finalRed = round(sqrt((gxRed * gxRed) + (gyRed * gyRed)));
            int finalGreen = round(sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));
            int finalBlue = round(sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));

            if (finalRed > 255)
            {
                finalRed = 255;
            }
            if (finalGreen > 255)
            {
                finalGreen = 255;
            }
            if (finalBlue > 255)
            {
                finalBlue = 255;
            }


            image[i][j].rgbtRed = finalRed;
            image[i][j].rgbtGreen = finalGreen;
            image[i][j].rgbtBlue = finalBlue;
        }
    }
    return;
}