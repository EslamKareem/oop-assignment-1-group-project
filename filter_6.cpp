#include <iostream>
#include "Image_Class.h"
using namespace std;

Image rotateImage(Image &img) {
    int choice;
    cout << "1. Rotate 90 2. Rotate 270 3. Rotate 180" << endl;
    cin >> choice;

    if (choice == 1) {
        Image rotated_image(img.height, img.width);

        for (int i = 0; i < img.width; i++) {
            for (int j = 0; j < img.height; j++) {
                for (int k = 0; k < 3; k++) {
                    rotated_image.setPixel(img.height - 1 - j, i, k, img.getPixel(i, j, k));
                }
            }
        }
        return rotated_image;
    }

    else if (choice == 2) {
        Image rotated_image(img.height, img.width);
        for (int i = 0; i < img.width; i++) {
            for (int j = 0; j < img.height; j++) {
                for (int k = 0; k < 3; k++) {
                    rotated_image.setPixel(j, img.width - 1 - i, k, img.getPixel(i, j, k));
                }
            }
        }
        return rotated_image;
    }

    else if (choice == 3){
        for (int i= 0; i < img.width / 2; i++) {
          for (int j = 0; j < img.height; j++) {
            for (int k = 0; k < 3; k++) {
              unsigned char color = img.getPixel(i, j, k);
              img.setPixel(i, j, k, img.getPixel(img.width - i - 1, j, k));
              img.setPixel(img.width - i - 1, j, k, color); 
            }
          }
        }
        for (int j = 0; j < img.height / 2; j++) {
          for (int i = 0; i < img.width; i++) {
            for (int k = 0; k < 3; k++) {
              unsigned char color = img.getPixel(i, j, k);
              img.setPixel(i, j, k, img.getPixel(i, img.height - j - 1, k));
              img.setPixel(i, img.height - j - 1, k, color);
            }
          }
        }
    }
    else {
        cout << "Invalid choice.Try again." << endl;
    }
      return img;
}
int main(){
    Image image("luffy.jpg");
    Image rotated_image = rotateImage(image);
    rotated_image.saveImage("rotated_image2.jpg");

}
            