#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{ 
    for (int i =0; i < height; i++){
        for (int j = 0; j < width; j++){
            // calculate the average of three pixel values image[i][j]
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            // set them into rgbtRed, rgbtGreen and rgbtBlue
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            // safe image[i][j] for a time in value RGBTRIPLE
          RGBTRIPLE temp = image[i][j];
          // to set a pixel image[i][width -1 -j] into image[i][j]
          image[i][j] = image[i][width - 1 - j];
          // to set a safed pixel into image[i][width -1 -j]
          image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
