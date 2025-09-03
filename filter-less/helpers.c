#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE greyvalue =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = greyvalue;
            image[i][j].rgbtGreen = greyvalue;
            image[i][j].rgbtBlue = greyvalue;
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
            int sepia_red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) +
                                  (0.189 * image[i][j].rgbtBlue));
            int sepia_green =
                round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) +
                      (0.168 * image[i][j].rgbtBlue));
            int sepia_blue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) +
                                   (0.131 * image[i][j].rgbtBlue));
            if (sepia_red <= 255)
            {
                image[i][j].rgbtRed = sepia_red;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (sepia_green <= 255)
            {
                image[i][j].rgbtGreen = sepia_green;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepia_blue <= 255)
            {
                image[i][j].rgbtBlue = sepia_blue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, j = width / 2; i < j; i++)
    {
        for (int k = 0; k < height; k++)
        {
            BYTE temp_red = image[k][i].rgbtRed;
            BYTE temp_green = image[k][i].rgbtGreen;
            BYTE temp_blue = image[k][i].rgbtBlue;

            image[k][i].rgbtRed = image[k][width - 1 - i].rgbtRed;
            image[k][i].rgbtGreen = image[k][width - 1 - i].rgbtGreen;
            image[k][i].rgbtBlue = image[k][width - 1 - i].rgbtBlue;

            image[k][width - 1 - i].rgbtRed = temp_red;
            image[k][width - 1 - i].rgbtGreen = temp_green;
            image[k][width - 1 - i].rgbtBlue = temp_blue;
        }
    }
}