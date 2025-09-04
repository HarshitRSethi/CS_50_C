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
    // So i need to tackle blur
    // I need to create an extra arrray to store the computed value as I can't directly change the
    // orignal value as it will hinder calc. of other pixels Is there a way to save memory?? there
    // is I can create a array RGBTRIPLE buffer[height][2] Now I have to design loop according to it
    // First corners, I will hardcode it out

    RGBTRIPLE buffer_corners[4];
    buffer_corners[0].rgbtRed = round(
        (image[0][0].rgbtRed + image[1][0].rgbtRed + image[0][1].rgbtRed + image[1][1].rgbtRed) /
        4.0);
    buffer_corners[0].rgbtGreen = round((image[0][0].rgbtGreen + image[1][0].rgbtGreen +
                                         image[0][1].rgbtGreen + image[1][1].rgbtGreen) /
                                        4.0);
    buffer_corners[0].rgbtBlue = round((image[0][0].rgbtBlue + image[1][0].rgbtBlue +
                                        image[0][1].rgbtBlue + image[1][1].rgbtBlue) /
                                       4.0);

    buffer_corners[1].rgbtRed =
        round((image[0][width - 1].rgbtRed + image[1][width - 1].rgbtRed +
               image[0][width - 1 - 1].rgbtRed + image[1][width - 1 - 1].rgbtRed) /
              4.0);
    buffer_corners[1].rgbtGreen =
        round((image[0][width - 1].rgbtGreen + image[1][width - 1].rgbtGreen +
               image[0][width - 1 - 1].rgbtGreen + image[1][width - 1 - 1].rgbtGreen) /
              4.0);
    buffer_corners[1].rgbtBlue =
        round((image[0][width - 1].rgbtBlue + image[1][width - 1].rgbtBlue +
               image[0][width - 1 - 1].rgbtBlue + image[1][width - 1 - 1].rgbtBlue) /
              4.0);

    buffer_corners[2].rgbtRed =
        round((image[height - 1][0].rgbtRed + image[height - 1 - 1][0].rgbtRed +
               image[height - 1][1].rgbtRed + image[height - 1 - 1][1].rgbtRed) /
              4.0);
    buffer_corners[2].rgbtGreen =
        round((image[height - 1][0].rgbtGreen + image[height - 1 - 1][0].rgbtGreen +
               image[height - 1][1].rgbtGreen + image[height - 1 - 1][1].rgbtGreen) /
              4.0);
    buffer_corners[2].rgbtBlue =
        round((image[height - 1][0].rgbtBlue + image[height - 1 - 1][0].rgbtBlue +
               image[height - 1][1].rgbtBlue + image[height - 1 - 1][1].rgbtBlue) /
              4.0);

    buffer_corners[3].rgbtRed = round(
        (image[height - 1][width - 1].rgbtRed + image[height - 1 - 1][width - 1].rgbtRed +
         image[height - 1][width - 1 - 1].rgbtRed + image[height - 1 - 1][width - 1 - 1].rgbtRed) /
        4.0);
    buffer_corners[3].rgbtGreen =
        round((image[height - 1][width - 1].rgbtGreen + image[height - 1 - 1][width - 1].rgbtGreen +
               image[height - 1][width - 1 - 1].rgbtGreen +
               image[height - 1 - 1][width - 1 - 1].rgbtGreen) /
              4.0);
    buffer_corners[3].rgbtBlue =
        round((image[height - 1][width - 1].rgbtBlue + image[height - 1 - 1][width - 1].rgbtBlue +
               image[height - 1][width - 1 - 1].rgbtBlue +
               image[height - 1 - 1][width - 1 - 1].rgbtBlue) /
              4.0);

    RGBTRIPLE buffer_height[2][height - 2];
    for (int i = 1; i < height - 1; i++)
    {
        buffer_height[0][i].rgbtRed =
            round((image[i][0].rgbtRed + image[i - 1][0].rgbtRed + image[i - 1][1].rgbtRed +
                   image[i][1].rgbtRed + image[i + 1][1].rgbtRed + image[i + 1][0].rgbtRed) /
                  6.0);
        buffer_height[0][i].rgbtGreen =
            round((image[i][0].rgbtGreen + image[i - 1][0].rgbtGreen + image[i - 1][1].rgbtGreen +
                   image[i][1].rgbtGreen + image[i + 1][1].rgbtGreen + image[i + 1][0].rgbtGreen) /
                  6.0);
        buffer_height[0][i].rgbtBlue =
            round((image[i][0].rgbtBlue + image[i - 1][0].rgbtBlue + image[i - 1][1].rgbtBlue +
                   image[i][1].rgbtBlue + image[i + 1][1].rgbtBlue + image[i + 1][0].rgbtBlue) /
                  6.0);

        buffer_height[1][i].rgbtRed =
            round((image[i][width - 1].rgbtRed + image[i - 1][width - 1].rgbtRed +
                   image[i - 1][width - 1 - 1].rgbtRed + image[i][width - 1 - 1].rgbtRed +
                   image[i + 1][width - 1 - 1].rgbtRed + image[i + 1][width - 1].rgbtRed) /
                  6.0);
        buffer_height[1][i].rgbtGreen =
            round((image[i][width - 1].rgbtGreen + image[i - 1][width - 1].rgbtGreen +
                   image[i - 1][width - 1 - 1].rgbtGreen + image[i][width - 1 - 1].rgbtGreen +
                   image[i + 1][width - 1 - 1].rgbtGreen + image[i + 1][width - 1].rgbtGreen) /
                  6.0);
        buffer_height[1][i].rgbtBlue =
            round((image[i][width - 1].rgbtBlue + image[i - 1][width - 1].rgbtBlue +
                   image[i - 1][width - 1 - 1].rgbtBlue + image[i][width - 1 - 1].rgbtBlue +
                   image[i + 1][width - 1 - 1].rgbtBlue + image[i + 1][width - 1].rgbtBlue) /
                  6.0);
    }

    RGBTRIPLE buffer_width[2][width - 2];
    for (int i = 1; i < width - 1; i++)
    {
        buffer_width[0][i].rgbtRed =
            round((image[0][i].rgbtRed + image[0][i + 1].rgbtRed + image[0][i - 1].rgbtRed +
                   image[1][i - 1].rgbtRed + image[1][i].rgbtRed + image[1][i + 1].rgbtRed) /
                  6.0);
        buffer_width[0][i].rgbtGreen =
            round((image[0][i].rgbtGreen + image[0][i + 1].rgbtGreen + image[0][i - 1].rgbtGreen +
                   image[1][i - 1].rgbtGreen + image[1][i].rgbtGreen + image[1][i + 1].rgbtGreen) /
                  6.0);
        buffer_width[0][i].rgbtBlue =
            round((image[0][i].rgbtBlue + image[0][i + 1].rgbtBlue + image[0][i - 1].rgbtBlue +
                   image[1][i - 1].rgbtBlue + image[1][i].rgbtBlue + image[1][i + 1].rgbtBlue) /
                  6.0);

        buffer_width[1][i].rgbtRed =
            round((image[height - 1][i].rgbtRed + image[height - 1][i - 1].rgbtRed +
                   image[height - 1][i + 1].rgbtRed + image[height - 1 - 1][i - 1].rgbtRed +
                   image[height - 1 - 1][i].rgbtRed + image[height - 1 - 1][i + 1].rgbtRed) /
                  6.0);
        buffer_width[1][i].rgbtGreen =
            round((image[height - 1][i].rgbtGreen + image[height - 1][i - 1].rgbtGreen +
                   image[height - 1][i + 1].rgbtGreen + image[height - 1 - 1][i - 1].rgbtGreen +
                   image[height - 1 - 1][i].rgbtGreen + image[height - 1 - 1][i + 1].rgbtGreen) /
                  6.0);
        buffer_width[1][i].rgbtBlue =
            round((image[height - 1][i].rgbtBlue + image[height - 1][i - 1].rgbtBlue +
                   image[height - 1][i + 1].rgbtBlue + image[height - 1 - 1][i - 1].rgbtBlue +
                   image[height - 1 - 1][i].rgbtBlue + image[height - 1 - 1][i + 1].rgbtBlue) /
                  6.0);
    }

    RGBTRIPLE buffer[height][2];
    for (int j = 1; j < width; j++)
    {
        for (int i = 1; i < height; i++)
        {
            buffer[i][j % 2].rgbtRed =
                round((double) (image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed +
                                image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed +
                                image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed +
                                image[i][j - 1].rgbtRed) /
                      9.0);
            buffer[i][j % 2].rgbtGreen =
                round((double) (image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen +
                                image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen +
                                image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                image[i][j - 1].rgbtGreen) /
                      9.0);
            buffer[i][j % 2].rgbtBlue =
                round((double) (image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue +
                                image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue +
                                image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue +
                                image[i][j - 1].rgbtBlue) /
                      9.0);
            if (j > 1)
                image[i][j - 1] = buffer[i][(j - 1) % 2];
            if (j == width - 1)

                image[i][j] = buffer[i][j % 2];
        }
    }
    image[0][0] = buffer_corners[0];
    image[0][width - 1] = buffer_corners[1];
    image[height - 1][0] = buffer_corners[2];
    image[height - 1][width - 1] = buffer_corners[3];

    for (int i = 1; i < height - 1; i++)
    {
        image[i][0] = buffer_height[0][i];
        image[i][width - 1] = buffer_height[1][i];
    }

    for (int i = 1; i < width - 1; i++)
    {
        image[0][i] = buffer_width[0][i];
        image[height - 1][i] = buffer_width[1][i];
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    typedef struct
    {
        double x;
        double y;
        double final;
    } g;

    g red[height][width];
    g green[height][width];
    g blue[height][width];

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            red[i][j].x = (image[i - 1][j - 1].rgbtRed * -1) + (image[i][j - 1].rgbtRed * -2) +
                          (image[i + 1][j - 1].rgbtRed * -1) + (image[i - 1][j + 1].rgbtRed * 1) +
                          (image[i][j + 1].rgbtRed * 2) + (image[i + 1][j + 1].rgbtRed * 1);
            red[i][j].y = (image[i - 1][j - 1].rgbtRed * -1) + (image[i + 1][j - 1].rgbtRed * 1) +
                          (image[i - 1][j].rgbtRed * -2) + (image[i + 1][j].rgbtRed * 2) +
                          (image[i - 1][j + 1].rgbtRed * -1) + (image[i + 1][j + 1].rgbtRed * 1);
            red[i][j].final = round(sqrt(pow(red[i][j].x, 2) + pow(red[i][j].y, 2)));

            green[i][j].x =
                (image[i - 1][j - 1].rgbtGreen * -1) + (image[i][j - 1].rgbtGreen * -2) +
                (image[i + 1][j - 1].rgbtGreen * -1) + (image[i - 1][j + 1].rgbtGreen * 1) +
                (image[i][j + 1].rgbtGreen * 2) + (image[i + 1][j + 1].rgbtGreen * 1);
            green[i][j].y = (image[i - 1][j - 1].rgbtGreen * -1) +
                            (image[i + 1][j - 1].rgbtGreen * 1) + (image[i - 1][j].rgbtGreen * -2) +
                            (image[i + 1][j].rgbtGreen * 2) + (image[i - 1][j + 1].rgbtGreen * -1) +
                            (image[i + 1][j + 1].rgbtGreen * 1);
            green[i][j].final = round(sqrt(pow(green[i][j].x, 2) + pow(green[i][j].y, 2)));

            blue[i][j].x = (image[i - 1][j - 1].rgbtBlue * -1) + (image[i][j - 1].rgbtBlue * -2) +
                           (image[i + 1][j - 1].rgbtBlue * -1) +
                           (image[i - 1][j + 1].rgbtBlue * 1) + (image[i][j + 1].rgbtBlue * 2) +
                           (image[i + 1][j + 1].rgbtBlue * 1);
            blue[i][j].y = (image[i - 1][j - 1].rgbtBlue * -1) +
                           (image[i + 1][j - 1].rgbtBlue * 1) + (image[i - 1][j].rgbtBlue * -2) +
                           (image[i + 1][j].rgbtBlue * 2) + (image[i - 1][j + 1].rgbtBlue * -1) +
                           (image[i + 1][j + 1].rgbtBlue * 1);
            blue[i][j].final = round(sqrt(pow(blue[i][j].x, 2) + pow(blue[i][j].y, 2)));
        }
    }

    for (int i = 1; i < height - 1; i++)
    {
        red[i][0].x =
            (image[i - 1][1].rgbtRed) + (image[i][1].rgbtRed * 2) + (image[i + 1][1].rgbtRed);
        red[i][width - 1].x = (image[i - 1][width - 1 - 1].rgbtRed * -1) +
                              (image[i][width - 1 - 1].rgbtRed * -2) +
                              (image[i + 1][width - 1 - 1].rgbtRed * -1);

        red[i][0].y = (image[i - 1][1].rgbtRed * -1) + (image[i - 1][0].rgbtRed * -2) +
                      (image[i + 1][1].rgbtRed * 1) + (image[i + 1][0].rgbtRed * 2);
        red[i][width - 1].y =
            (image[i - 1][width - 1 - 1].rgbtRed * -1) + (image[i - 1][width - 1].rgbtRed * -2) +
            (image[i + 1][width - 1 - 1].rgbtRed * 1) + (image[i + 1][width - 1].rgbtRed * 2);

        red[i][0].final = round(sqrt(pow(red[i][0].x, 2) + pow(red[i][0].y, 2)));
        red[i][width - 1].final =
            round(sqrt(pow(red[i][width - 1].x, 2) + pow(red[i][width - 1].y, 2)));

        green[i][0].x =
            (image[i - 1][1].rgbtGreen) + (image[i][1].rgbtGreen * 2) + (image[i + 1][1].rgbtGreen);
        green[i][width - 1].x = (image[i - 1][width - 1 - 1].rgbtGreen * -1) +
                                (image[i][width - 1 - 1].rgbtGreen * -2) +
                                (image[i + 1][width - 1 - 1].rgbtGreen * -1);

        green[i][0].y = (image[i - 1][1].rgbtGreen * -1) + (image[i - 1][0].rgbtGreen * -2) +
                        (image[i + 1][1].rgbtGreen * 1) + (image[i + 1][0].rgbtGreen * 2);
        green[i][width - 1].y = (image[i - 1][width - 1 - 1].rgbtGreen * -1) +
                                (image[i - 1][width - 1].rgbtGreen * -2) +
                                (image[i + 1][width - 1 - 1].rgbtGreen * 1) +
                                (image[i + 1][width - 1].rgbtGreen * 2);

        green[i][0].final = round(sqrt(pow(green[i][0].x, 2) + pow(green[i][0].y, 2)));
        green[i][width - 1].final =
            round(sqrt(pow(green[i][width - 1].x, 2) + pow(green[i][width - 1].y, 2)));

        blue[i][0].x =
            (image[i - 1][1].rgbtBlue) + (image[i][1].rgbtBlue * 2) + (image[i + 1][1].rgbtBlue);
        blue[i][width - 1].x = (image[i - 1][width - 1 - 1].rgbtBlue * -1) +
                               (image[i][width - 1 - 1].rgbtBlue * -2) +
                               (image[i + 1][width - 1 - 1].rgbtBlue * -1);

        blue[i][0].y = (image[i - 1][1].rgbtBlue * -1) + (image[i - 1][0].rgbtBlue * -2) +
                       (image[i + 1][1].rgbtBlue * 1) + (image[i + 1][0].rgbtBlue * 2);
        blue[i][width - 1].y =
            (image[i - 1][width - 1 - 1].rgbtBlue * -1) + (image[i - 1][width - 1].rgbtBlue * -2) +
            (image[i + 1][width - 1 - 1].rgbtBlue * 1) + (image[i + 1][width - 1].rgbtBlue * 2);

        blue[i][0].final = round(sqrt(pow(blue[i][0].x, 2) + pow(blue[i][0].y, 2)));
        blue[i][width - 1].final =
            round(sqrt(pow(blue[i][width - 1].x, 2) + pow(blue[i][width - 1].y, 2)));
    }

    for (int i = 1; i < width - 1; i++)
    {
        red[0][i].x = (image[0][i - 1].rgbtRed * -2) + (image[0][i + 1].rgbtRed * 2) +
                      (image[1][i - 1].rgbtRed * -1) + (image[1][i + 1].rgbtRed * 1);
        red[height - 1][i].x = (image[height - 1][i - 1].rgbtRed * -2) +
                               (image[height - 1][i + 1].rgbtRed * 2) +
                               (image[height - 1 - 1][i - 1].rgbtRed * -1) +
                               (image[height - 1 - 1][i + 1].rgbtRed * 1);

        red[0][i].y = (image[1][i - 1].rgbtRed * 1) + (image[1][i].rgbtRed * 2) +
                      (image[1][i + 1].rgbtRed * 1);
        red[height - 1][i].y = (image[height - 1 - 1][i - 1].rgbtRed * -1) +
                               (image[height - 1 - 1][i].rgbtRed * -2) +
                               (image[height - 1 - 1][i + 1].rgbtRed * -1);

        red[0][i].final = round(sqrt(pow(red[0][i].x, 2) + pow(red[0][i].y, 2)));
        red[height - 1][i].final =
            round(sqrt(pow(red[height - 1][i].x, 2) + pow(red[height - 1][i].y, 2)));

        green[0][i].x = (image[0][i - 1].rgbtGreen * -2) + (image[0][i + 1].rgbtGreen * 2) +
                        (image[1][i - 1].rgbtGreen * -1) + (image[1][i + 1].rgbtGreen * 1);
        green[height - 1][i].x = (image[height - 1][i - 1].rgbtGreen * -2) +
                                 (image[height - 1][i + 1].rgbtGreen * 2) +
                                 (image[height - 1 - 1][i - 1].rgbtGreen * -1) +
                                 (image[height - 1 - 1][i + 1].rgbtGreen * 1);

        green[0][i].y = (image[1][i - 1].rgbtGreen * 1) + (image[1][i].rgbtGreen * 2) +
                        (image[1][i + 1].rgbtGreen * 1);
        green[height - 1][i].y = (image[height - 1 - 1][i - 1].rgbtGreen * -1) +
                                 (image[height - 1 - 1][i].rgbtGreen * -2) +
                                 (image[height - 1 - 1][i + 1].rgbtGreen * -1);

        green[0][i].final = round(sqrt(pow(green[0][i].x, 2) + pow(green[0][i].y, 2)));
        green[height - 1][i].final =
            round(sqrt(pow(green[height - 1][i].x, 2) + pow(green[height - 1][i].y, 2)));

        blue[0][i].x = (image[0][i - 1].rgbtBlue * -2) + (image[0][i + 1].rgbtBlue * 2) +
                       (image[1][i - 1].rgbtBlue * -1) + (image[1][i + 1].rgbtBlue * 1);
        blue[height - 1][i].x = (image[height - 1][i - 1].rgbtBlue * -2) +
                                (image[height - 1][i + 1].rgbtBlue * 2) +
                                (image[height - 1 - 1][i - 1].rgbtBlue * -1) +
                                (image[height - 1 - 1][i + 1].rgbtBlue * 1);

        blue[0][i].y = (image[1][i - 1].rgbtBlue * 1) + (image[1][i].rgbtBlue * 2) +
                       (image[1][i + 1].rgbtBlue * 1);
        blue[height - 1][i].y = (image[height - 1 - 1][i - 1].rgbtBlue * -1) +
                                (image[height - 1 - 1][i].rgbtBlue * -2) +
                                (image[height - 1 - 1][i + 1].rgbtBlue * -1);

        blue[0][i].final = round(sqrt(pow(blue[0][i].x, 2) + pow(blue[0][i].y, 2)));
        blue[height - 1][i].final =
            round(sqrt(pow(blue[height - 1][i].x, 2) + pow(blue[height - 1][i].y, 2)));
    }
    red[0][0].x = (image[0][1].rgbtRed * 2) + (image[1][1].rgbtRed * 1);
    red[0][width - 1].x =
        (image[0][width - 1 - 1].rgbtRed * -2) + (image[1][width - 1 - 1].rgbtRed * -1);
    red[height - 1][0].x =
        (image[height - 1][1].rgbtRed * 2) + (image[height - 1 - 1][1].rgbtRed * 1);
    red[height - 1][width - 1].x = (image[height - 1][width - 1 - 1].rgbtRed * 2) +
                                   (image[height - 1 - 1][width - 1 - 1].rgbtRed);

    red[0][0].y = (image[1][0].rgbtRed * 2) + (image[1][1].rgbtRed * 1);
    red[0][width - 1].y = (image[1][width - 1].rgbtRed * 2) + (image[1][width - 1 - 1].rgbtRed * 1);
    red[height - 1][0].y =
        (image[height - 1 - 1][0].rgbtRed * -2) + (image[height - 1 - 1][1].rgbtRed * -1);
    red[height - 1][width - 1].y = (image[height - 1 - 1][width - 1].rgbtRed * -2) +
                                   (image[height - 1 - 1][width - 1 - 1].rgbtRed * -1);

    red[0][0].final = round(sqrt(pow(red[0][0].x, 2) + pow(red[0][0].y, 2)));
    red[0][width - 1].final =
        round(sqrt(pow(red[0][width - 1].x, 2) + pow(red[0][width - 1].y, 2)));
    red[height - 1][0].final =
        round(sqrt(pow(red[height - 1][0].x, 2) + pow(red[height - 1][0].y, 2)));
    red[height - 1][width - 1].final =
        round(sqrt(pow(red[height - 1][width - 1].x, 2) + pow(red[height - 1][width - 1].y, 2)));

    green[0][0].x = (image[0][1].rgbtGreen * 2) + (image[1][1].rgbtGreen * 1);
    green[0][width - 1].x =
        (image[0][width - 1 - 1].rgbtGreen * -2) + (image[1][width - 1 - 1].rgbtGreen * -1);
    green[height - 1][0].x =
        (image[height - 1][1].rgbtGreen * 2) + (image[height - 1 - 1][1].rgbtGreen * 1);
    green[height - 1][width - 1].x = (image[height - 1][width - 1 - 1].rgbtGreen * 2) +
                                     (image[height - 1 - 1][width - 1 - 1].rgbtGreen);

    green[0][0].y = (image[1][0].rgbtGreen * 2) + (image[1][1].rgbtGreen * 1);
    green[0][width - 1].y =
        (image[1][width - 1].rgbtGreen * 2) + (image[1][width - 1 - 1].rgbtGreen * 1);
    green[height - 1][0].y =
        (image[height - 1 - 1][0].rgbtGreen * -2) + (image[height - 1 - 1][1].rgbtGreen * -1);
    green[height - 1][width - 1].y = (image[height - 1 - 1][width - 1].rgbtGreen * -2) +
                                     (image[height - 1 - 1][width - 1 - 1].rgbtGreen * -1);

    green[0][0].final = round(sqrt(pow(green[0][0].x, 2) + pow(green[0][0].y, 2)));
    green[0][width - 1].final =
        round(sqrt(pow(green[0][width - 1].x, 2) + pow(green[0][width - 1].y, 2)));
    green[height - 1][0].final =
        round(sqrt(pow(green[height - 1][0].x, 2) + pow(green[height - 1][0].y, 2)));
    green[height - 1][width - 1].final = round(
        sqrt(pow(green[height - 1][width - 1].x, 2) + pow(green[height - 1][width - 1].y, 2)));

    blue[0][0].x = (image[0][1].rgbtBlue * 2) + (image[1][1].rgbtBlue * 1);
    blue[0][width - 1].x =
        (image[0][width - 1 - 1].rgbtBlue * -2) + (image[1][width - 1 - 1].rgbtBlue * -1);
    blue[height - 1][0].x =
        (image[height - 1][1].rgbtBlue * 2) + (image[height - 1 - 1][1].rgbtBlue * 1);
    blue[height - 1][width - 1].x = (image[height - 1][width - 1 - 1].rgbtBlue * 2) +
                                    (image[height - 1 - 1][width - 1 - 1].rgbtBlue);

    blue[0][0].y = (image[1][0].rgbtBlue * 2) + (image[1][1].rgbtBlue * 1);
    blue[0][width - 1].y =
        (image[1][width - 1].rgbtBlue * 2) + (image[1][width - 1 - 1].rgbtBlue * 1);
    blue[height - 1][0].y =
        (image[height - 1 - 1][0].rgbtBlue * -2) + (image[height - 1 - 1][1].rgbtBlue * -1);
    blue[height - 1][width - 1].y = (image[height - 1 - 1][width - 1].rgbtBlue * -2) +
                                    (image[height - 1 - 1][width - 1 - 1].rgbtBlue * -1);

    blue[0][0].final = round(sqrt(pow(blue[0][0].x, 2) + pow(blue[0][0].y, 2)));
    blue[0][width - 1].final =
        round(sqrt(pow(blue[0][width - 1].x, 2) + pow(blue[0][width - 1].y, 2)));
    blue[height - 1][0].final =
        round(sqrt(pow(blue[height - 1][0].x, 2) + pow(blue[height - 1][0].y, 2)));
    blue[height - 1][width - 1].final =
        round(sqrt(pow(blue[height - 1][width - 1].x, 2) + pow(blue[height - 1][width - 1].y, 2)));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (red[i][j].final > 255)
                red[i][j].final = 255;

            if (green[i][j].final > 255)
                green[i][j].final = 255;

            if (blue[i][j].final > 255)
                blue[i][j].final = 255;

            image[i][j].rgbtRed = red[i][j].final;
            image[i][j].rgbtGreen = green[i][j].final;
            image[i][j].rgbtBlue = blue[i][j].final;
        }
    }
    return;
}