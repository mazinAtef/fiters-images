
// FCI – Programming 1 – 2022 - Mazen[20210317]
// Program Name: Mazen[20210317].cpp
// Last Modification Date: 7/4/2021
// Author1 and ID and Group: Mazen Atef Mohammed [20210317] {A}
// Teaching Assistant:  ِAfaf
//section: 11,12

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
void menu();
void loadImage();
void loadImage2();
void saveImage();

void merge_images();
void dark_light();
void shrink();
void Blur_Image();

int main()
{
    while (1)
    {
        int choice;
        menu();
        cin >> choice;
        if (choice == 3)
        {
            merge_images();
        }
        else if (choice == 6)
        {
            dark_light();
        }
        else if (choice == 9)
        {
            shrink();
        }
        else if (choice == 12)
        {
            Blur_Image();
        }

        else if (choice == 0)
        {
            break;
        }
        saveImage();
    }
    return 0;
}
void loadImage() {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void loadImage2() {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}
void saveImage() {
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
void merge_images()//3
{
    //To download the first image
    loadImage();
    //To download the second image
    loadImage2();
    //to loop on the rows
    for (int i = 0; i < 255; i++) {
        //to loop on the columns
        for (int j = 0; j < 255; j++) {
            //to calculate the average
            image3[i][j] = (image2[i][j] + image[i][j]) / 2;
        }
    }
    //to print the new image
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            image[i][j] = image3[i][j];
        }
    }
}
void dark_light()//6
{
    int x;
    //To download the image
    loadImage();
    //to choice my decision
    cout << "do you want to make the photo: \n" << "1-lighter\n" << "2-darker\n";
    cin >> x;
    // if to choice the lighter
    if (x == 1) {
        //to loop on the rows
        for (int i = 0; i < 255; i++) {
            //to loop on the columns
            for (int j = 0; j < 256; j++) {
                image[i][j] += (256 - image[i][j]) / 2;
            }
        }
    }
    //if to choice the darker
    else if (x == 2) {
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 256; j++) {
                image[i][j] -= image[i][j] / 2;
            }
        }
    }
}
void shrink()//9
{
    int x;
    //To download the image
    loadImage();
    // To choice the size of the zoom out
    cout << "do u want to shrink the image to: \n";
    cout << "1-(1/2) \n" << "2-(1/3) \n" << "3-(1/4) \n";
    cin >> x;
    //to choose to zoom out to[1/2]
    if (x == 1)
    {
        //to loop on the rows
        for (int i = 0; i < 255; i += 2) {
            //to loop on the columns
            for (int j = 0; j < 255; j += 2) {
                image3[(i - 1) / 2][(j - 1) / 2] = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            }
        }
        // to print the new image
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {
                image[i][j] = image3[i][j];
            }
        }
    }
    //to choose to zoom out to[1/3]
    else if (x == 2)
    {
        for (int i = 0; i < 255; i += 2) {
            for (int j = 0; j < 255; j += 2) {
                image3[(i - 1) / 3][(j - 1) / 3] = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            }
        }
        // to print the new image
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {
                image[i][j] = image3[i][j];
            }
        }
    }
    //to choose to zoom out to [1/4]
    else if (x == 3)
    {
        for (int i = 0; i < 255; i += 2) {
            for (int j = 0; j < 255; j += 2) {
                image3[(i - 1) / 4][(j - 1) / 4] = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            }
        }
        // to print the new image
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {
                image[i][j] = image3[i][j];
            }
        }

    }
}
void Blur_Image()//12
{
    //To download the image
    loadImage();
    double average;
    //to loop on the rows
    for (int i = 0; i < SIZE; i++) {
        //to loop on the columns
        for (int j = 0; j < SIZE; j++) {
            int sum = 0;
            sum = image[i][j] + image[i][j + 1] + image[i][j + 2] + image[i + 1][j] + image[i + 1][j + 1] + image[i + 1][j + 2] + image[i + 2][j] + image[i + 2][j + 1] + image[i + 2][j + 2];
            average = (sum / 9);
            // to print the new image
            image[i][j] = average;
        }
    }
}
void menu() {
    cout << "\t\t\t\t\t\t\[Enter your choice 20210317]";
    cout << endl << endl;
    cout << "3- Merge Filter\n";
    cout << "6- Darken and Lighten Image\n";
    cout << "9- Shrink Image\n";
    cout << "12- Blur Image\n";
    cout << "0- Exit\n";
}
