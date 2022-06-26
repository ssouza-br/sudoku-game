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
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tmpBluex = 0, tmpRedx = 0, tmpGreenx = 0, index_i = 0, index_j = 0, tmpBluey = 0, tmpRedy = 0, tmpGreeny = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    index_i = i + k;
                    index_j = j + m;
                    if (index_i >= 0 && index_j >= 0 && index_i <= height - 1 && index_j <= width - 1)
                    {
                        tmpBluex = tmpBluex + image[index_i][index_j].rgbtBlue * Gx[k+1][m+1];
                        tmpRedx = tmpRedx + image[index_i][index_j].rgbtRed * Gx[k+1][m+1];
                        tmpGreenx = tmpGreenx + image[index_i][index_j].rgbtGreen * Gx[k+1][m+1];

                        tmpBluey = tmpBluey + image[index_i][index_j].rgbtBlue * Gy[k+1][m+1];
                        tmpRedy = tmpRedy + image[index_i][index_j].rgbtRed * Gy[k+1][m+1];
                        tmpGreeny = tmpGreeny + image[index_i][index_j].rgbtGreen * Gy[k+1][m+1];
                    }
                    else
                    {
                        tmpBluex = tmpBluex + 0 * Gx[k+1][m+1];
                        tmpRedx = tmpRedx + 0 * Gx[k+1][m+1];
                        tmpGreenx = tmpGreenx + 0 * Gx[k+1][m+1];

                        tmpBluey = tmpBluey + 0 * Gy[k+1][m+1];
                        tmpRedy = tmpRedy + 0 * Gy[k+1][m+1];
                        tmpGreeny = tmpGreeny + 0 * Gy[k+1][m+1];
                    }
                }
            }

            new_image[i][j].rgbtBlue = (sqrt(tmpBluex * tmpBluex + tmpBluey * tmpBluey) > 255) ? 255 : round(sqrt(tmpBluex * tmpBluex + tmpBluey * tmpBluey));
            new_image[i][j].rgbtRed = (sqrt(tmpRedx * tmpRedx + tmpRedy * tmpRedy) > 255) ? 255 : round(sqrt(tmpRedx * tmpRedx + tmpRedy * tmpRedy));
            new_image[i][j].rgbtGreen = (sqrt(tmpGreenx * tmpGreenx + tmpGreeny * tmpGreeny) > 255) ? 255 : round(sqrt(tmpGreenx * tmpGreenx + tmpGreeny * tmpGreeny));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}