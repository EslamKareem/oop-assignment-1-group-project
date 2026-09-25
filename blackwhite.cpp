#include <iostream>
#include "Image_Class.h"
using namespace std;

int main(){
    Image image("luffy.jpg");
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; k++) {
                 avg += image(i,j,k);
            }
            avg /= 3;
            if(avg >= 128){
                for (int k = 0; k < 3; k++) {
                    image(i,j,k) = 255;
                }
            }
            else{
                for (int k = 0; k < 3; k++) {
                    image(i,j,k) = 0;
                }
            }
        }
    } 
    image.saveImage("luffy2.jpg");     
}