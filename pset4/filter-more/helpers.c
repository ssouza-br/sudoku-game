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
    int tmpBlue1 = 0, tmpRed1 = 0, tmpGreen1 = 0, tmpBlue2 = 0, tmpRed2 = 0, tmpGreen2 = 0;
    //RGBTRIPLE tmp1, tmp2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmpBlue1 = image[i][j].rgbtBlue;
            tmpRed1 = image[i][j].rgbtRed;
            tmpGreen1 = image[i][j].rgbtGreen;

            tmpBlue2 = image[i][width - j - 1].rgbtBlue;
            tmpRed2 = image[i][width - j- 1].rgbtRed;
            tmpGreen2 = image[i][width - j- 1].rgbtGreen;

            image[i][j].rgbtBlue = tmpBlue2;
            image[i][j].rgbtRed = tmpRed2;
            image[i][j].rgbtGreen = tmpGreen2;

            image[i][width - j- 1].rgbtBlue = tmpBlue1;
            image[i][width - j- 1].rgbtRed = tmpRed1;
            image[i][width - j- 1].rgbtGreen = tmpGreen1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
