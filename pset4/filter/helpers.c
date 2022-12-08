#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i < height;i++){
        for(int j=0; j < width;j++){
            RGBTRIPLE pixel = image[i][j];
            int average = round(((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed)/ 3.0 ));
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i < height;i++){
        for(int j=0; j < width;j++){
            RGBTRIPLE pixel = image[i][j];
            int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            if ( sepiaRed > 255 ){
                sepiaRed = 255;
            }


            if ( sepiaBlue > 255 ){
                sepiaBlue = 255;
            }

            if ( sepiaGreen > 255 ){
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

        for(int i=0; i < height;i++){

                for(int pos=0,k=width-1;k > -1 ;k--, pos++){

                //RGBTRIPLE pixel = image[i][j];

                temp[i][pos]=image[i][k];


                }

        }

         for(int i=0; i < height;i++){
            for(int j=0;j < width;j++){
                for(int k=width-1;k > -1 ;k--){

                //RGBTRIPLE pixel = image[i][j];


                image[i][j]=temp[i][j];


            }
        }
         }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0;i < height;i++){
        for(int j=0; j < width;j++){
            //RGBTRIPLE pixel = image[i][j];
            if (i == 0 && j==0 ){
            int averageBlue = round(((image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue)/ 3.0 ));
            int averageRed = round(((image[i+1][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed)/ 3.0 ));
            int averageGreen = round(((image[i+1][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen)/ 3.0 ));
            image[i][j].rgbtBlue =  averageBlue;
            image[i][j].rgbtRed =  averageRed;
            image[i][j].rgbtGreen =  averageGreen;
            }
            else if( i==0 ){
            int averageBlue = round(((image[i][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j+1].rgbtBlue)/ 5.0 ));
            int averageRed = round(((image[i][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j+1].rgbtRed)/ 5.0 ));
            int averageGreen = round(((image[i][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j+1].rgbtGreen)/ 5.0 ));
            image[i][j].rgbtBlue =  averageBlue;
            image[i][j].rgbtRed =  averageRed;
            image[i][j].rgbtGreen =  averageGreen;
            }
            else if( i==0 && j==width-1 ){
            int averageBlue = round(((image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/ 3.0 ));
            int averageRed = round(((image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/ 3.0 ));
            int averageGreen = round(((image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/ 3.0 ));
            image[i][j].rgbtBlue =  averageBlue;
            image[i][j].rgbtRed =  averageRed;
            image[i][j].rgbtGreen =  averageGreen;
            }
                else if(j == 0){
                int averageBlue = round((image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/5.0);
                int averageRed = round((image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/5.0);
                int averageGreen = round((image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/5.0);
                image[i][j].rgbtBlue =  averageBlue;
                image[i][j].rgbtRed =  averageRed;
                image[i][j].rgbtGreen =  averageGreen;
            }
                else if( i == height-1 && j==width-1){
                int averageBlue = round(((image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/ 3.0 ));
                int averageRed = round(((image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed)/ 3.0 ));
                int averageGreen = round(((image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/ 3.0 ));
                image[i][j].rgbtBlue =  averageBlue;
                image[i][j].rgbtRed =  averageRed;
                image[i][j].rgbtGreen =  averageGreen;  
            }
             else if(j==width-1){
                int averageBlue = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue)/5.0);
                int averageRed = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed)/5.0);
                int averageGreen = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen)/5.0);
                image[i][j].rgbtBlue =  averageBlue;
                image[i][j].rgbtRed =  averageRed;
                image[i][j].rgbtGreen =  averageGreen;
            }
            else if(i==height-1 && j==0){
                int averageBlue = round(((image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/ 3.0 ));
                int averageRed = round(((image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed)/ 3.0 ));
                int averageGreen = round(((image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/ 3.0 ));
                image[i][j].rgbtBlue =  averageBlue;
                image[i][j].rgbtRed =  averageRed;
                image[i][j].rgbtGreen =  averageGreen;
               }
               else if(i ==height-1){
                int averageBlue = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue)/5.0);
                int averageRed = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed)/5.0);
                int averageGreen = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen)/5.0);
                image[i][j].rgbtBlue =  averageBlue;
                image[i][j].rgbtRed =  averageRed;
                image[i][j].rgbtGreen =  averageGreen;
            }
            else{
                
                int averageBlue = round((image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue)/8.0);
                int averageRed = round((image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed+image[i-1][j-1].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed)/8.0);
                int averageGreen = round((image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen)/8.0);
                image[i][j].rgbtBlue =  averageBlue;
                image[i][j].rgbtRed =  averageRed;
                image[i][j].rgbtGreen =  averageGreen;
            }
               
            }

        }
    
    return;
}
