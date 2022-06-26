#include <stdio.h>
#include <math.h>

int main(void)
{
    int tmpBlue = 0, tmpRed = 0, tmpGreen = 0, counter = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    int index_i = i + k, index_j = j + m;
                    if (index_i >= 0 && index_j >= 0)
                    {
                        tmpBlue = tmpBlue + image[index_i][index_j].rgbtBlue;
                        tmpRed = tmpRed + image[index_i][index_j].rgbtRed;
                        tmpGreen = tmpGreen + image[index_i][index_j].rgbtGreen;
                        counter++;
                    }
                }

            }
            image[i][j].rgbtBlue = round((float) tmpBlue / counter);
            image[i][j].rgbtRed = round((float) tmpRed / counter);
            image[i][j].rgbtGreen = round((float) tmpGreen / counter);
        }
    }
}