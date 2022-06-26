#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int tmpBlue = 0, tmpRed = 0, tmpGreen = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmpBlue = image[i][j].rgbtBlue;
            tmpRed = image[i][j].rgbtRed;
            tmpGreen = image[i][j].rgbtGreen;

            int avgValue = round(((float) tmpBlue + (float) tmpRed + (float) tmpGreen) / 3);

            image[i][j].rgbtBlue = avgValue;
            image[i][j].rgbtRed = avgValue;
            image[i][j].rgbtGreen = avgValue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp1, tmp2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp1 = image[i][j];
            tmp2 = image[i][width - j - 1];

            image[i][j] = tmp2;
            image[i][width - j - 1] = tmp1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int tmpBlue = 0, tmpRed = 0, tmpGreen = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp1 = image[i][j];
            tmp2 = image[i][width - j - 1];

            image[i][j] = tmp2;
            image[i][width - j - 1] = tmp1;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
