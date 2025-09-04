#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double buffer = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = buffer;
            image[i][j].rgbtGreen = buffer;
            image[i][j].rgbtBlue = buffer;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    for (int i = 0; i < width / 2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            buffer = image[j][i];
            image[j][i] = image[j][width - i - 1];
            image[j][width - i - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Redsum = 0;
            int Greensum = 0;
            int Bluesum = 0;
            int counter = 0;
            for (int di = -1; di < 2; di++)
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    if ((ni >= 0) && (ni < height) && (nj >= 0) && (nj < width))
                    {
                        Redsum += image[ni][nj].rgbtRed;
                        Greensum += image[ni][nj].rgbtGreen;
                        Bluesum += image[ni][nj].rgbtBlue;
                        counter++;
                    }
                }
            }
            copy[i][j].rgbtRed = round((float) Redsum / counter);
            copy[i][j].rgbtGreen = round((float) Greensum / counter);
            copy[i][j].rgbtBlue = round((float) Bluesum / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            image[i][j] = copy[i][j];
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // {(0,0),(0,1),(0,2)
    //  (1,0),(1,1),(1,2)
    //  (2,0),(2,1),(2,2)}
int Gx[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int RedsumGx = 0;
            int GreensumGx = 0;
            int BluesumGx = 0;
            int RedsumGy = 0;
            int GreensumGy = 0;
            int BluesumGy = 0;
            for (int di = 0; di < 3; di++)
            {
                for (int dj = 0; dj < 3; dj++)
                {
                    int ni = i + di - 1;
                    int nj = j + dj - 1;

                    if ((ni >= 0) && (ni < height) && (nj >= 0) && (nj < width))
                    {
                        RedsumGx += image[ni][nj].rgbtRed * Gx[di][dj];
                        GreensumGx += image[ni][nj].rgbtGreen * Gx[di][dj];
                        BluesumGx += image[ni][nj].rgbtBlue * Gx[di][dj];
                        RedsumGy += image[ni][nj].rgbtRed * Gy[di][dj];
                        GreensumGy += image[ni][nj].rgbtGreen * Gy[di][dj];
                        BluesumGy += image[ni][nj].rgbtBlue * Gy[di][dj];
                    }
                }
            }
            RedsumGx = round(sqrt(pow(RedsumGx, 2) + pow(RedsumGy, 2)));
            if (RedsumGx > 255)
                copy[i][j].rgbtRed = 255;
            else
                copy[i][j].rgbtRed = RedsumGx;

            GreensumGx = round(sqrt(pow(GreensumGx, 2) + pow(GreensumGy, 2)));
            if (GreensumGx > 255)
                copy[i][j].rgbtGreen = 255;
            else
                copy[i][j].rgbtGreen = GreensumGx;

            BluesumGx = round(sqrt(pow(BluesumGx, 2) + pow(BluesumGy, 2)));
            if (BluesumGx > 255)
                copy[i][j].rgbtBlue = 255;
            else
                copy[i][j].rgbtBlue = BluesumGx;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width ; j++)
            image[i][j] = copy[i][j];
    }
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
                image[i][j].rgbtRed = sepia_red;
            else
                image[i][j].rgbtRed = 255;

            if (sepia_green <= 255)
                image[i][j].rgbtGreen = sepia_green;
            else
                image[i][j].rgbtGreen = 255;

            if (sepia_blue <= 255)
                image[i][j].rgbtBlue = sepia_blue;
            else
                image[i][j].rgbtBlue = 255;
        }
    }
    return;
}