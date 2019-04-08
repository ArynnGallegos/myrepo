/* IMPORTANT NOTES:
 * This is just a sample code.
 * You may/should change/delete many parts of this file.
 * You can just get some hints on how to start your code here.
 * DO NOT consider this file as a template. 
 */


#include <iostream>
#include "bmplib.h"
#include <dirent.h>
#define PATH_IN "~/ee355/Lab6/"
#define PATH_OUT "~/ee355/Lab6Output/"
using namespace std;

void showMainMenu(){
    cout << "0: Exit \n";
    cout << "1: Flip 90 \n";
    cout << "2: Flip 180 \n";
    cout << "3: Mirror \n";
    cout << "4: Grey Scaling \n";
    cout << "5: Color Inversion \n";
    cout << "6: Zoom In \n";
    cout << "7: WaterMark \n";
    cout << "8: Copy \n";
    
}


void copy(string filename, unsigned char dest[SIZE][SIZE][3]){

    unsigned char src[SIZE][SIZE][3];
    readRGBBMP(filename.c_str(), src);

    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            for (int k=0; k<3; k++){
                dest[i][j][k] = src[i][j][k];
            }
        }
    }
}

void flip90(string filename)
{
    unsigned char src[SIZE][SIZE][RGB];
    unsigned char dest[SIZE][SIZE][RGB];
    unsigned char temp[SIZE][SIZE][RGB];
    readRGBBMP(filename.c_str(), src);
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int c=0; c<3; c++)
            {
                temp[i][j][c] = src[j][i][c];
            }
        }
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int c=0; c<3; c++)
            {
                dest[i][j][c] = temp[i][SIZE-1-j][c];
            }
        }
    }
    showRGBBMP(dest);
    writeRGBBMP("fruit-flip90.bmp", dest);
}

void flip180(string filename)
{
    unsigned char src[SIZE][SIZE][RGB];
    unsigned char dest[SIZE][SIZE][RGB];
    unsigned char temp[SIZE][SIZE][RGB];
    unsigned char temp2[SIZE][SIZE][RGB];
    readRGBBMP(filename.c_str(), src);
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int c=0; c<3; c++)
            {
                temp[i][j][c] = src[j][i][c];
            }
        }
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int c=0; c<3; c++)
            {
                temp2[i][j][c] = temp[i][SIZE-1-j][c];
            }
        }
    }
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int c=0; c<3; c++)
            {
                dest[i][j][c] = temp2[j][i][c];
            }
        }
    }
    showRGBBMP(dest);
    writeRGBBMP("fruit-flip180.bmp", dest);
}

void mirror(string filename)
{
    unsigned char src[SIZE][SIZE][RGB];
    unsigned char dest[SIZE][SIZE][RGB];
    readRGBBMP("fruit.bmp", src);
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int c=0; c<3; c++)
            {
                dest[i][j][c] = src[i][SIZE-1-j][c];
            }
        }
    }
    writeRGBBMP("fruit-mirror.bmp", dest);
}

void grey(string filename)
{
    unsigned char src[SIZE][SIZE][RGB];
    unsigned char dest[SIZE][SIZE];
    readRGBBMP("fruit.bmp", src);
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            unsigned char r = src[i][j][0];
            unsigned char g = src[i][j][1];
            unsigned char b = src[i][j][2];
            dest[i][j] = (unsigned char)(.299*r + .587*g + .114*b);
        }
    }
    writeGSBMP("fruit-grayscale.bmp", dest);
    showGSBMP(dest);
}

void color_inversion(string filename)
{
    unsigned char src[SIZE][SIZE][RGB];
    unsigned char dest[SIZE][SIZE][RGB];
    readRGBBMP("fruit.bmp", src);
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            for (int c=0; c<3; c++) {
                dest[i][j][c] = 255-src[i][j][c];
            }
        }
    }
    showRGBBMP(dest);
    writeRGBBMP("fruit-inverse.bmp", dest);
}

void zoom(string filename)
{
    unsigned char in[SIZE][SIZE];
    unsigned char out[SIZE][SIZE];
    readGSBMP("elephant.bmp", in);

    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
        out[i][j] = in[SIZE/4 + i/2][SIZE/4 + j/2];
        }
    }

    writeGSBMP("elephant-zoom.bmp", out);
}

int main(){

    int option;
    string fileName;
    unsigned char res [SIZE][SIZE][3];
    while(1){
        cout << "\033[2J\033[1;1H";
        showMainMenu();
        cout << "Select an option: ";
        cin >> option;
        if (option==0)
        {
            cout << "EXIT \n";;
            return 0;
        }
        else if (option == 1) 
        {
            cout << "FLIP 90 \n";
            flip90(fileName);
            break;
        }        
        else if (option == 2)
        {
            cout << "FLIP 180 \n";
            flip180(fileName);
            break;
        } 
        else if (option == 3)
        {
            cout << "MIRROR \n";
            mirror(fileName);
            break;
        }
        else if (option == 4)
        {
            cout << "GREY SCALING \n";
            grey(fileName);
            break;
        }
        else if (option == 5)
        {
            cout << "COLOR INVERSION \n";
            color_inversion(fileName);
            break;
        }
        else if (option == 6) //need to look at more closly
        {
            cout << "ZOOM IN \n";
            zoom(fileName);
            break;
        }
        else if (option == 7)
        {
            cout << "WATERMARK \n";
            cout << "currently not available \n";
            break;
        }
        else if (option == 8)
        {
            cout << "COPY \n";
            copy("./fruit.bmp", res);
            writeRGBBMP("image_copy.bmp", res);
            break;
        }
        else
        {
            cout << "OPTION NOT FOUND! \n";
            break;
        }
    
    }

    return 0;
}
