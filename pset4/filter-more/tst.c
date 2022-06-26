#include <stdio.h>
#include <math.h>

// first row: (10, 20, 30), (40, 50, 60), (70, 80, 90)
// second row: (110, 130, 140), (120, 140, 150), (130, 150, 160)
// third row: (200, 210, 220), (220, 230, 240), (240, 250, 255)


int main(void)
{
    int height = 3, width = 3;
    int image[3][3];
    int new_image[3][3];
    image[0][0] = 10;
    image[0][1] = 40;
    image[0][2] = 70;

    image[1][0] = 110;
    image[1][1] = 120;
    image[1][2] = 130;

    image[2][0] = 200;
    image[2][1] = 220;
    image[2][2] = 240;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int counter = 0;
            int tmpBlue = 0, tmpRed = 0, tmpGreen = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    int index_i = i + k, index_j = j + m;
                    if (index_i >= 0 && index_j >= 0 && index_i <= height - 1 && index_j <= width - 1 )
                    {
                        //printf("i: %i j: %i index_i: %i index_j: %i\n", i, j, index_i, index_j);
                        tmpBlue = tmpBlue + image[index_i][index_j];
                        counter++;
                    }
                }
            }
            // printf("counter: %i\n", counter);
            new_image[i][j] = round((float) tmpBlue / counter);
            // printf("i: %i j: %i res: %i\n",i, j, new_image[i][j]);
        }
    }
    image = new_image;
    printf("\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("i: %i j: %i res: %i\n",i, j, image[i][j]);
        }
    }
}