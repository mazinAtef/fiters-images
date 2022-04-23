
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
#include <conio.h>

using namespace std;
unsigned char colored[256][256][3];
unsigned char temp[256][256][3];
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE][RGB];
void menu();
void loadImage ();
void loadImage2 ();
void saveImage ();

void merge_images();
void dark_light();
void shrink();
void Blur_Image ();
void black_and_white();
void flipi_mage();
void Invert_Filter();
void Rotate_Image();
void enlarge();
void Mirror_Image ();
void Shuffle_Image();

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

         flipi_mage();
      }
      else if (choice==5)
      {
          Rotate_Image();
      }
      else if (choice==6)
      {
          dark_light();
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
           Mirror_Image ();
      }
      else if (choice==11)
      {
           Shuffle_Image ();
      }
      else if (choice==12)
      {
           Blur_Image();
      }
      else if (choice==0)
      {
          break;
      }saveImage();

  }
  return 0;
}

void loadImage () {
   char imageFileName[100];
   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}
void loadImage2 () {
   char imageFileName[100];
   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image2);
}
void saveImage () {
   char imageFileName[100];
   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;
   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
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
    for (int j = 0; j< 255; j++) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
            //to calculate the average
            image3[i][j][k]=(image2[i][j][k]+image[i][j][k])/2;
        }
    }
  }
    //to print the new image
    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
            image[i][j][k]=image3[i][j][k];}
    }
    }
}

void dark_light()//6
{
    int x;
    //To download the image
    loadImage();
  //to choice my decision
  cout<<"do you want to make the photo: \n"<<"1-lighter\n"<<"2-darker\n";
  cin>>x;
  // if to choice the lighter
  if (x==1){
  //to loop on the rows
  for (int i = 0; i <255; i++) {
    //to loop on the columns
    for (int j = 0; j< 256; j++) {
            //to loop on the RGB
            for (int k =0 ; k <3; k++){
          image[i][j][k]+=(256-image[i][j][k])/2;}
  }
  }}
  //if to choice the darker
  else if (x==2){
    for (int i = 0; i <255; i++) {
    for (int j = 0; j< 256; j++) {
            //to loop on the RGB
            for (int k =0 ; k <3; k++){
       image[i][j][k]-=image[i][j][k]/2;}
  }
}}
}

void shrink()//9
{
    int x;
    //To download the image
    loadImage();
    // To choice the size of the zoom out
    cout<<"do u want to shrink the image to: \n";
    cout<<"1-(1/2) \n"<<"2-(1/3) \n"<<"3-(1/4) \n";
    cin>>x;
    //to choose to zoom out to[1/2]
    if(x==1)
    {
        //to loop on the rows
        for (int i = 0; i < 255; i+=2) {
    //to loop on the columns
    for (int j = 0; j< 255; j+=2) {
            //to loop on the RGB
      for (int k =0 ; k <3; k++){
        image3[(i-1)/2][(j-1)/2][k]=(image[i][j][k]+image[i][j+1][k]+image[i+1][j][k]+image[i+1][j+1][k])/4;}
    }
    }
    // to print the new image
    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
        image[i][j][k]=image3[i][j][k];}
    }
    }
    }
    //to choose to zoom out to[1/3]
    else if (x==2)
    {
    for (int i = 0; i < 255; i+=2) {
    for (int j = 0; j< 255; j+=2) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
        image3[(i-1)/3][(j-1)/3][k]=(image[i][j][k]+image[i][j+1][k]+image[i+1][j][k]+image[i+1][j+1][k])/4;}
    }
    }
    // to print the new image
    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
        image[i][j][k]=image3[i][j][k];}
    }
    }
    }
    //to choose to zoom out to [1/4]
    else if(x==3)
    {
        for (int i = 0; i < 255; i+=2) {
    for (int j = 0; j< 255; j+=2) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
        image3[(i-1)/4][(j-1)/4][k]=(image[i][j][k]+image[i][j+1][k]+image[i+1][j][k]+image[i+1][j+1][k])/4;}
    }
    }
    // to print the new image
    for (int i = 0; i < 255; i++) {
    for (int j = 0; j< 255; j++) {
            //to loop on the RGB
        for (int k =0 ; k <3; k++){
        image[i][j][k]=image3[i][j][k];}
    }
    }

    }
}

void Blur_Image(){
    //To download the image
    loadImage();
    double average;

    //to loop on the rows
    for (int i = 0; i <SIZE; i++) {
             //to loop on the columns
        for (int j = 0; j<SIZE; j++) {
                //to loop on the RGB
            for (int k =0 ; k <3; k++){
                int sum = 0;
                sum = image[i ][j ][k] + image[i ][j+1][k] + image[i][j + 2][k] + image[i+1][j][k] + image[i+1][j+1][k] +image[i+1][j +2][k] + image[i +2][j ][k] + image[i + 2][j+1][k] + image[i + 2][j + 2][k];
                average = (sum / 9);
                // to print the new image
                image[i][j][k] = average;
            }

        }
    }
}


void Mirror_Image()
 {
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
                  for (int k =0 ; k <3; k++){
                 image[i][j][k]=image[i][255-j][k];}
             }
         }
     }
     if (mirror ==2)
     {
         for (int i=0; i<SIZE; i++)
         {
             for (int j=0; j<SIZE; j++)
             {
                  for (int k =0 ; k <3; k++){
                 image[i][255-j][k]=image[i][j][k];}
             }
         }
     }
     if (mirror==3)
     {
         for (int i=0; i<SIZE; i++)
         {
             for (int j=0; j<SIZE; j++)
             {
                  for (int k =0 ; k <3; k++){
                 image[i][j][k]=image[SIZE-1/255-i][j][k];}
             }
         }
     }
     if (mirror==4)
     {
         for (int i=0; i<SIZE; i++)
         {
             for (int j =0; j<SIZE; j++)
             {
                  for (int k =0 ; k <3; k++){
                 image[SIZE-1/255-i][j][k]=image[i][j][k];}
             }
         }
     }
 }


void enlarge()
{
    loadImage();
    int choose;
    cout<< "choose \n"<< "1-first quarter \n"<< "2-second\n"<< "3-third \n"<< "4-fourth \n";
    cin>> choose;
    if (choose==1){

    for(int i=0 ,k=0 ; i<SIZE/2 ; i++ , k+=2)
    {
        for(int j=0,n=0 ;j<SIZE/2 ; j++ ,n+=2)
        {
            for(int x=0; x<3 ;x++)
            {
                temp[k][n][x]=colored[i][j][x];
                temp[k+1][n][x]=colored[i][j][x];
                temp[k][n+1][x]=colored[i][j][x];
                temp[k+1][n+1][x]=colored[i][j][x];

            }

        }
    }
    writeRGBBMP("test1.bmp", temp);
    }
    else if (choose==2)
    {
        for(int i=0 ,k=0 ; i<SIZE/2 ; i++ , k+=2)
    {
        for(int j=SIZE/2,n=0;j<SIZE ; j++ ,n+=2)
        {
            for(int x=0;x<3 ;x++)
            {
                temp[k][n][x]=colored[i][j][x];
                temp[k+1][n][x]=colored[i][j][x];
                temp[k][n+1][x]=colored[i][j][x];
                temp[k+1][n+1][x]=colored[i][j][x];
            }

        }
    }
    writeRGBBMP("test2.bmp", temp);
    saveImage();

    }

 else if (choose==3){
        for(int i=SIZE/2 ,k=0 ; i<SIZE ; i++ , k+=2)
    {
        for(int j=0,n=0;j<SIZE/2 ; j++ ,n+=2)
        {
            for(int x=0 ;x<3 ;x++)
            {
                temp[k][n][x]=colored[i][256-j][x];
                temp[k+1][n][x]=colored[i][256-j][x];
                temp[k][n+1][x]=colored[i][256-j][x];
                temp[k+1][n+1][x]=colored[i][256-j][x];
            }

        }
    }
    writeRGBBMP("test3.bmp", temp);

}

 else if (choose==4){
        for(int i=SIZE/2 ,k=0 ; i<SIZE ; i++ , k+=2)
    {
        for(int j=SIZE/2,n=0;j<SIZE ; j++ ,n+=2)
        {
            for(int x=0 ;x<3 ;x++)
            {
                temp[k][n][x]=colored[i][j][x];
                temp[k+1][n][x]=colored[i][j][x];
                temp[k][n+1][x]=colored[i][j][x];
                temp[k+1][n+1][x]=colored[i][j][x];
            }

        }
    }
    writeRGBBMP("test4.bmp", temp);

}
}

void darken_lighten_Image() {

        int operation;
        for (int i = 0; i < SIZE; i++)
          {
             for (int j = 0; j< SIZE; j++)
             {
                 for(int k=0; k<3 ;k++)
                 {
                     if (operation==1)
                 {
                     colored[i][j][k]=(colored[i][j][k])/2;
                 }
                 if (operation==2)
                 {
                        if (colored[i][j][k]<=127 )
                       {
                          colored[i][j][k]=(colored[i][j][k])+70;
                       }
                        else if (colored[i][j][k]<=255)
                        {
                           colored[i][j][k]=(colored[i][j][k]);
                        }

                 }
                 }

             }
          }
}


void Shuffle_Image() {
    loadImage();
loop:
    int x1, x2, x3, x4;
    cout << "Enter the order of the shuffle that you want" << endl;
    cin >> x1 >> x2 >> x3 >> x4;
    unsigned char temp[256][256][3];
    if (x1 == 1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][j][k] = image[i][j][k];}
            }
        }
    }
    else if (x1 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][j][k] = image[i][j + 128][k];}
            }
        }
    }
    else if (x1 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][j][k] = image[i + 128][j][k];}
            }
        }
    }
    else if (x1 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][j][k] = image[i + 128][j + 128][k];}
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
                     for (int k =0 ; k <3; k++){
                temp[i][j + 128][k] = image[i][j][k];}
            }
        }
    }
    else if (x2 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][j + 128][k] = image[i][j + 128][k];}
            }
        }
    }
    else if (x2 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][j + 128][k] = image[i + 128][j][k];}
            }
        }
    }
    else if (x2 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i][128][k] = image[i + 128][j + 128][k];}
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
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j][k] = image[i][j][k];}
            }
        }
    }
    else if (x3 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j][k] = image[i][j + 128][k];}
            }
        }
    }
    else if (x3 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j][k] = image[i + 128][j][k];}
            }
        }
    }
    else if (x3 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[+128][j][k] = image[i + 128][j + 128][k];}
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
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j + 128][k] = image[i][j][k];}
            }
        }
    }
    else if (x4 == 2) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j + 128][k] = image[i][j + 128][k];}
            }
        }
    }
    else if (x4 == 3) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j + 128][k] = image[i + 128][j][k];}
            }
        }
    }
    else if (x4 == 4) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                     for (int k =0 ; k <3; k++){
                temp[i + 128][j + 128][k] = image[i + 128][j + 128][k];}
            }
        }
    }
    else {
        cout << "Out of range, please try again" << endl;
        goto loop;
    }
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
                 for (int k =0 ; k <3; k++){
            image[i][j][k] = temp[i][j][k];}
        }
    }
}


void Invert_Filter()
{
    loadImage();
  for (int i = 0; i <255; i++) {
    for (int j = 0; j< 256; j++) {
            for (int k =0 ; k <3; k++){
          image[i][j][k]=256-image[i][j][k];}
}
  }
}


void flipi_mage() {
    loadImage();

  for (int i = 0; i < 128; i++) {
    for (int j = 0; j< 256; j++) {
            for (int k =0 ; k <3; k++){
            swap(image [i][j][k], image[256-i][256-j][k]);}

    }
  }
}


void black_and_white()
{
     loadImage();

  for (int i = 0; i <256; i++) {
    for (int j = 0; j< 256; j++) {
      for (int k =0 ; k <3; k++){
          if (image[i][j][k]<127){image[i][j][k]=0;}
          else
            image[i][j][k]=255;

      }
    }
  }
}


void Rotate_Image()
{
    loadImage();
    int m , mode ;
    cout<<"how do you want to rotate the image??\n1-rotate 90 degree.\n2-rotate 180 degree.\n3-rotate 270 degree."<<endl;
    cin>>mode;
    if(mode==1){
        for (int i = 0; i < (SIZE); i++){
            for (int j =i+1; j< (SIZE); j++) {
                    for(int x=0 ;x<3 ;x++)
                    {
                         swap(colored[i][j][x],colored[j][i][x]);
                    }

            }
        }
        for (int i = 0; i < SIZE; i++ ){
            for (int j = 0; j < SIZE/2; j += 1){
                    for(int x=0 ; x<3 ;x++)
                    {
                        swap(colored[j][i][x], colored[SIZE-j-1][i][x]);
                    }
            }
        }
    }
    if(mode==2)
    {
        for(int i=0 ;i<SIZE/2 ;i++)
        {
            for(int j=0 ;j<SIZE ;j++)
            {
                for(int x=0; x<3 ;x++)
                {
                    m=colored[i][j][x];
                    colored[i][j][x]=colored[SIZE-1-i][SIZE-1-j][x];
                    colored[SIZE-1-i][SIZE-1-j][x]=m;
                }

            }
        }
    }
    if(mode==3)
    {
        for (int i = 0; i < (SIZE); i++){
            for (int j =i+1; j< (SIZE); j++) {
                    for(int x=0 ;x<3 ;x++)
                    {
                        swap(colored[i][j][x],colored[j][i][x]);
                    }

            }
        }
        for (int i = 0; i < SIZE; i++ ){
            for (int j = 0; j < SIZE/2; j += 1){
                    for(int x=0 ;x<3 ;x++)
                    {
                         swap(colored[j][i][x], colored[SIZE-j-1][i][x]);
                    }

            }
        }
        for(int i=0 ;i<SIZE/2 ;i++)
        {
            for(int j=0 ;j<SIZE ;j++)
            {
                for(int x=0 ; x<3 ;x++)
                {
                     m=colored[i][j][x];
                    colored[i][j][x]=colored[SIZE-1-i][SIZE-1-j][x];
                    colored[SIZE-1-i][SIZE-1-j][x]=m;
                }

            }
        }


    }
}











void menu() {

  cout<<"\t\t\t\t\t\t\[Enter your choice]";
  cout<<endl<<endl;
  cout<<"1- Black & White Filter \n";
  cout<<"2- Invert Filter\n";
  cout<<"3- Merge Filter\n";
  cout<<"4- Flip Image\n";
  cout<<"5- Rotate Image\n";
  cout<<"6- Darken and Lighten Image\n";
  cout<<"7- Detect Image Edges\n";
  cout<<"8- Enlarge Image\n";
  cout<<"9- Shrink Image\n";
  cout<<"10- Mirror Image\n";
  cout<<"11- Shuffle Image\n";
  cout<<"12- Blur Image\n";
  //cout<<"s- Save the image to a file;
  cout<<"0- Exit\n";
}
