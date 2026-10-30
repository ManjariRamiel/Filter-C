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
int cap(int value){
    if (value > 255){
        return 255;
    }
    return value;
    }
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            // calculate sepia values
            int sepiaRed = cap(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            int sepiaGreen = cap(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            int sepiaBlue = cap(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
            // set sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
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
