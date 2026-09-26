#include "Image_Class.h"
#include <iostream>
using namespace std;
void lightenImage(Image &image, int amount) {
  double ratio = amount / 100.0;
  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      for (int k = 0; k < 3; k++) {
        int pixelValue = image.getPixel(i, j, k) * (1 + ratio);
        if (pixelValue > 255) {
          pixelValue = 255;
        } else if (pixelValue < 0) {
          pixelValue = 0;
        }
        image.setPixel(i, j, k, pixelValue);
      }
    }
  }
}
void darkenImage(Image &image, int amount) {
  double ratio = amount / 100.0;
  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      for (int k = 0; k < 3; k++) {
        int pixelValue = image.getPixel(i, j, k) * (1 - ratio);
        if (pixelValue > 255) {
          pixelValue = 255;
        } else if (pixelValue < 0) {
          pixelValue = 0;
        }
        image.setPixel(i, j, k, pixelValue);
      }
    }
  }
}
int main() {
  Image myPicture("building.jpg");

  int choice;
  cout << "Choose an option:\n";
  cout << "1. Lighten the image\n";
  cout << "2. Darken the image\n";
  cin >> choice;

  int amount;
  cout << "Enter the amounte  (0-100): ";
  cin >> amount;

  if (choice == 1) {
    lightenImage(myPicture, amount);
    myPicture.saveImage("building_lightened.jpg");
  } else if (choice == 2) {
    darkenImage(myPicture, amount);
    myPicture.saveImage("building_darkened.jpg");
  } else {
    std::cout << "Invalid choice. Please select 1 or 2." << endl;
  }
  return 0;
}
