#include <stdio.h>
#include <math.h>

int main(void)
{
    int tmpBlue = 0, tmpRed = 0, tmpGreen = 0, counter = 0, height = 3, width = 3;
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
                        printf("i: %i j: %i index_i: %i index_j: %i\n", i, j, index_i, index_j);
                        counter++;
                    }
                }

            }
        }
    }
    printf("counter: %i\n", counter);
}