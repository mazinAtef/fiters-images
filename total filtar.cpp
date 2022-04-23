// FCI – Programming 1 – 2022 - Assignment 3
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
void loadImage ();
void loadImage2 ();
void saveImage ();

void black_and_white();
void flipimage();
void merge_images();
void Invert_Filter();
void dark_light();
void Rotate_Image();
void edges();
void enlarge();
void shrink();
void MirrorImage ();
void ShuffleImage();
void BlurImage ();

int main()
{
  while(1)
  {
      int choice;
      menu();
      cin>>choice;
      if (choice == 1)
      {
          black_and_white();
      }
      else if (choice==2)
      {
          Invert_Filter();
      }
      else if (choice==3)
      {
          merge_images();
      }
      else if (choice==4)
      {
          flipimage();
      }
      else if (choice==5)
      {
          Rotate_Image();
      }
      else if (choice==6)
      {
          dark_light();
      }
      else if (choice==7)
      {
          edges();
      }
      else if (choice==8)
      {
          enlarge();
      }
      else if (choice==9)
      {
           shrink();
      }
      else if (choice==10)
      {
           MirrorImage ();
      }
      else if (choice == 11)
      {
      ShuffleImage();
      }
      else if (choice == 12)
      {
      BlurImage();
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
void black_and_white(){
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
void merge_images(){
    loadImage();
    loadImage2();
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            image3[i][j] = (image2[i][j] + image[i][j]) / 2;
        }
    }
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            image[i][j] = image3[i][j];
        }
    }
}
void Invert_Filter(){
    loadImage();
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = 256 - image[i][j];
        }
    }
}
void dark_light(){
    int x;
    loadImage();

    cout << "do you want to make the photo: \n" << "1-lighter\n" << "2-darker\n";
    cin >> x;

    if (x == 1) {
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 256; j++) {

                image[i][j] += (256 - image[i][j]) / 2;


            }
        }
    }
    else if (x == 2) {

        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 256; j++) {
                image[i][j] -= image[i][j] / 2;

            }


        }
    }
}

void transpose(unsigned char image1[][256], int n){
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++)
            swap(image1[i][j], image1[j][i]);
    }
}
void reverse(unsigned char image1[][256], int n){
    for (int i = 0; i < (n / 2); i++) {

        for (int j = 0; j < n; j++)
            swap(image1[i][j], image1[n - i - 1][j]);
    }
}
void Rotate_Image() {
    loadImage();

    int n = 256;
    int rotation_degree;

    cout << "please choose:\n"
        "1-90 degree\n"
        "2-180 degree\n"
        "3-270 degree\n"
        "4-360 degree\n";
    cin >> rotation_degree;

    if (rotation_degree == 1) {

        transpose(image, n);
        reverse(image, n);
    }

    else if (rotation_degree == 2) {

        transpose(image, n);
        reverse(image, n);
        transpose(image, n);
        reverse(image, n);


    }

    else if (rotation_degree == 3) {
        transpose(image, n);
        reverse(image, n);
        transpose(image, n);
        reverse(image, n);
        transpose(image, n);
        reverse(image, n);


    }

    else if (rotation_degree == 4) {
        transpose(image, n);
        reverse(image, n);
        transpose(image, n);
        reverse(image, n);
        transpose(image, n);
        reverse(image, n);
        transpose(image, n);
        reverse(image, n);


    }
}

void edges(){
    loadImage();
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 256; j++) {
            if (abs(image[i][j] - image[i][j + 1] > 25)) { image[i][j] = 0; }
            else
                image[i][j] = 255;
        }
    }
}
void enlarge(){
    loadImage();
    for (int i = 0; i < 128; i++) {
        int a = i, b;
        for (int j = 0; j < 128; j++) {
            b = j * 2;
            for (int k = a; k < i + 2; k++) {
                for (int m = b; m < b + 4; m++) {
                    image2[k][m] = image[i][j];
                }
            }
        }
    }
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image[i][j] = image2[i][j];
        }
    }

}
void shrink(){
    int x;
    loadImage();

    cout << "do u want to shrink the image to: \n";
    cout << "1-(1/2) \n" << "2-(1/3) \n" << "3-(1/4) \n";
    cin >> x;

    if (x == 1)
    {
        for (int i = 0; i < 255; i += 2) {
            for (int j = 0; j < 255; j += 2) {

                image3[(i - 1) / 2][(j - 1) / 2] = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            }
        }

        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {

                image[i][j] = image3[i][j];
            }
        }

    }

    else if (x == 2)
    {


        for (int i = 0; i < 255; i += 2) {
            for (int j = 0; j < 255; j += 2) {

                image3[(i - 1) / 3][(j - 1) / 3] = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            }
        }

        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {

                image[i][j] = image3[i][j];
            }
        }
    }

    else if (x == 3)
    {
        for (int i = 0; i < 255; i += 2) {
            for (int j = 0; j < 255; j += 2) {

                image3[(i - 1) / 4][(j - 1) / 4] = (image[i][j] + image[i][j + 1] + image[i + 1][j] + image[i + 1][j + 1]) / 4;
            }
        }

        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {

                image[i][j] = image3[i][j];
            }
        }

    }
}
void MirrorImage(){
     loadImage();
     cout << "please choose the half you want to make mirror for : \n 1-1st half \n 2- 2nd half \n 3- 3rd half \n 4- 4th half.\n" ;
     int mirror=0;
     cin >> mirror;
     if (mirror==1)
     {
         for (int i=0; i<SIZE; i++)
         {
             for(int j=0; j<SIZE; j++)
             {
                 image[i][j]=image[i][255-j];
             }
         }
     }
     if (mirror ==2)
     {
         for (int i=0; i<SIZE; i++)
         {
             for (int j=0; j<SIZE; j++)
             {
                 image[i][255-j]=image[i][j];
             }
         }
     }
     if (mirror==3)
     {
         for (int i=0; i<SIZE; i++)
         {
             for (int j=0; j<SIZE; j++)
             {
                 image[i][j]=image[SIZE-1/255-i][j];
             }
         }
     }
     if (mirror==4)
     {
         for (int i=0; i<SIZE; i++)
         {
             for (int j =0; j<SIZE; j++)
             {
                 image[SIZE-1/255-i][j]=image[i][j];
             }
         }
     }
 }
void BlurImage() {
    loadImage();
    double average;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int sum = 0;
            sum = image[i][j] + image[i][j + 1] + image[i][j + 2] + image[i + 1][j] + image[i + 1][j + 1] + image[i + 1][j + 2] + image[i + 2][j] + image[i + 2][j + 1] + image[i + 2][j + 2];
            average = (sum / 9);
            image[i][j] = average;
        }
    }
}
void ShuffleImage() {
    loadImage();
loop:
    int x1, x2, x3, x4;
    cout << "Enter the order of the shuffle that you want" << endl;
    cin >> x1 >> x2 >> x3 >> x4;
    unsigned char temp[256][256];
    if (x1 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j] = image[i][j];
            }
        }
    }
    else if (x1 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j] = image[i][j + 128];
            }
        }
    }
    else if (x1 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j] = image[i + 128][j];
            }
        }
    }
    else if (x1 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j] = image[i + 128][j + 128];
            }
        }
    }
    else {
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    if (x2 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j + 128] = image[i][j];
            }
        }
    }
    else if (x2 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j + 128] = image[i][j + 128];
            }
        }
    }
    else if (x2 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][j + 128] = image[i + 128][j];
            }
        }
    }
    else if (x2 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i][128] = image[i + 128][j + 128];
            }
        }
    }
    else {
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    if (x3 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j] = image[i][j];
            }
        }
    }
    else if (x3 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j] = image[i][j + 128];
            }
        }
    }
    else if (x3 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j] = image[i + 128][j];
            }
        }
    }
    else if (x3 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[+128][j] = image[i + 128][j + 128];
            }
        }
    }
    else {
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    if (x4 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j + 128] = image[i][j];
            }
        }
    }
    else if (x4 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j + 128] = image[i][j + 128];
            }
        }
    }
    else if (x4 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j + 128] = image[i + 128][j];
            }
        }
    }
    else if (x4 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                temp[i + 128][j + 128] = image[i + 128][j + 128];
            }
        }
    }
    else {
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            image[i][j] = temp[i][j];
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






