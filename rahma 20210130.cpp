// FCI � Programming 1 � 2022 - Assignment 3
// Program Name: assignment 3.cpp
// Last Modification Date: 7/4/2021
// Author1 and ID and Group: Mazen Atef Mohammed [20210317] {A}
// Author2 and ID and Group: Mohammed Ehab Said  [20210332] {A}
// Author3 and ID and Group: Rahma Khaled [20210130] {A}
// Teaching Assistant:  ?Afaf
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

void black_and_white();
void flipimage();

;
void edges();

void MirrorImage();


int main()
{
    while (1)
    {
        int choice;
        menu();
        cin >> choice;
        if (choice == 1)
        {
            black_and_white();
        }

        else if (choice == 4)
        {
            flipimage();
        }

        else if (choice == 7)
        {
            edges();
        }

        else if (choice == 10)
        {
            MirrorImage();
        }

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








void black_and_white() {
    loadImage();
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            if (image[i][j] < 127) { image[i][j] = 0; }
            else
                image[i][j] = 255;
        }
    }
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






void flipimage() {
    loadImage();
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 256; j++) {
            swap(image[i][j], image[256 - i][256 - j]);
        }
    }
}


void edges() {
    loadImage();
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 256; j++) {
            if (abs(image[i][j] - image[i][j + 1] > 25)) { image[i][j] = 0; }
            else
                image[i][j] = 255;
        }
    }
}




void MirrorImage() {
    loadImage();
    cout << "please choose the half you want to make mirror for : \n 1-1st half \n 2- 2nd half \n 3- 3rd half \n 4- 4th half.\n";
    int mirror = 0;
    cin >> mirror;
    if (mirror == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[i][255 - j];
            }
        }
    }
    if (mirror == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][255 - j] = image[i][j];
            }
        }
    }
    if (mirror == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[SIZE - 1 / 255 - i][j];
            }
        }
    }
    if (mirror == 4)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[SIZE - 1 / 255 - i][j] = image[i][j];
            }
        }
    }
}












void menu() {

    cout << "Enter your choice:";
    cout << endl << endl;
    cout << "1- Black & White Filter \n";
    cout << "2- Invert Filter\n";
    cout << "3- Merge Filter\n";
    cout << "4- Flip Image\n";
    cout << "5- Rotate Image\n";
    cout << "6- Darken and Lighten Image\n";
    cout << "7- Detect Image Edges\n";
    cout << "8- Enlarge Image\n";
    cout << "9- Shrink Image\n";
    cout << "10- Mirror Image\n";
    cout << "11- Shuffle Image\n";
    cout << "12- Blur Image\n";
    cout << "0- Exit\n";
}






