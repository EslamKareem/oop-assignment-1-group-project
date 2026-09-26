#include "Image_Class.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD
void blackWhite(Image image) {
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
    image.saveImage();   
    return;  
=======
int main() {
  Image image("luffy.jpg");
  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      unsigned int avg = 0;
      for (int k = 0; k < 3; k++) {
        avg += image(i, j, k);
      }
      avg /= 3;
      if (avg >= 128) {
        for (int k = 0; k < 3; k++) {
          image(i, j, k) = 255;
        }
      } else {
        for (int k = 0; k < 3; k++) {
          image(i, j, k) = 0;
        }
      }
    }
  }
  image.saveImage("luffy2.jpg");
>>>>>>> 83ed2c3b193ce2044e21a862bae1915012422aae
}