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
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int tmpBlue = 0, tmpRed = 0, tmpGreen = 0, index_i = 0, index_j = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    index_i = i + k;
                    index_j = j + m;
                    if (index_i >= 0 && index_j >= 0 && index_i <= height - 1 && index_j <= width - 1)
                    {
                        tmpBlue = tmpBlue + image[index_i][index_j].rgbtBlue;
                        tmpRed = tmpRed + image[index_i][index_j].rgbtRed;
                        tmpGreen = tmpGreen + image[index_i][index_j].rgbtGreen;
                        counter++;
                    }
                }
            }
            new_image[i][j].rgbtBlue = round((float) tmpBlue / counter);
            new_image[i][j].rgbtRed = round((float) tmpRed / counter);
            new_image[i][j].rgbtGreen = round((float) tmpGreen / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
            return;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
