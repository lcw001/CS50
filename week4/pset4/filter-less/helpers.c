#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            int average = (int)(image[column][row].rgbtBlue + image[column][row].rgbtGreen + image[column][row].rgbtRed) / 3.0 + 0.5;

            image[column][row].rgbtBlue = average;
            image[column][row].rgbtGreen = average;
            image[column][row].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            int originalRed = image[column][row].rgbtRed;
            int originalGreen = image[column][row].rgbtGreen;
            int originalBlue = image[column][row].rgbtBlue;

            image[column][row].rgbtRed = fmin(255, (int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue + 0.5));
            image[column][row].rgbtGreen = fmin(255, (int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue + 0.5));
            image[column][row].rgbtBlue = fmin(255, (int)(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue + 0.5));
        }
    }return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width / 2; row++)
        {
            //swap right side and left side
            RGBTRIPLE temp = image[column][row];
            image[column][row] = image[column][width - 1 - row];
            image[column][width - 1 - row] = temp;
         }
    }return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            temp[column][row] = image[column][row];
        }
    }

    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            int totalred = 0;
            int totalgreen = 0;
            int totalblue = 0;
            float counter = 0.00;

            for (int x = - 1; x < 2; x++)
            {
                for (int y = - 1; y < 2; y++)
                {
                   int currentx = column + x;
                   int currenty = row + y;

                   if (currentx < 0 || currentx > (height - 1) || currenty < 0 || currenty > (width -1))
                   {
                    continue;
                   }
                totalred += image[currentx][currenty].rgbtRed;
                totalgreen += image[currentx][currenty].rgbtGreen;
                totalblue += image[currentx][currenty].rgbtBlue;

                counter++;
                }
            }
            temp[column][row].rgbtRed = round(totalred / counter);
            temp[column][row].rgbtGreen = round(totalgreen / counter);
            temp[column][row].rgbtBlue = round(totalblue / counter);
        }
    }
    for (int column = 0; column < height; column++)
    {
        for (int row = 0; row < width; row++)
        {
            image[column][row] = temp[column][row];
        }
    }return;
}
