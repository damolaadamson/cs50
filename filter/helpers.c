#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++) //Loop to select every individual pixel in the image
    {
        for (int j = 0, w = width; j < w; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int avg = round(((float)blue + (float)green + (float)red) / 3); //Finds the average of all RGB values
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = avg; //Replaces all RGB values with the average value
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue); //Calculates a new blue value using the previous RGB values
            if (sepiaBlue > 255) //Replaces new value with 255 if it is greater than the maximum value for an 8-bit color value
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue); //Calculates a new green value using the previous RGB values
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue); //Calculates a new red value using the previous RGB values
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w / 2; j++) //Loop to select every individual pixel on the left side of the image
        {
            RGBTRIPLE tmp = image[i][j]; //Temporarily stores pixels on the left side of the image
            image[i][j] = image[i][w - (j + 1)]; //Replaces pixels on the left side of the image with pixels on the right
            image[i][w - (j + 1)] = tmp; //Replaces pixels on the right side of image with temporarily stored pixels
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            tmp[i][j] = image[i][j]; //Temporarily stores copy of the image
        }
    }

    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            float avg_blue, avg_green, avg_red;
            int counter;
            avg_blue = avg_green = avg_red = counter = 0;
            for (int k = -1; k < 2; k++) //Loop to check for pixels surrounding every pixel
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k > (h - 1)) //Skips if there is no surrounding pixel
                    {
                        continue;
                    }
                    if (j + l < 0 || j + l > (w - 1)) //Skips if there is no surrounding pixel
                    {
                        continue;
                    }
                    avg_blue += tmp[i + k][j + l].rgbtBlue;
                    avg_green += tmp[i + k][j + l].rgbtGreen;
                    avg_red += tmp[i + k][j + l].rgbtRed;
                    counter++;
                }
            }
            //Finds average of each value and replaces the pixel in original image
            image[i][j].rgbtBlue = round(avg_blue / counter);
            image[i][j].rgbtGreen = round(avg_green / counter);
            image[i][j].rgbtRed = round(avg_red / counter);
        }
    }
    return;
}