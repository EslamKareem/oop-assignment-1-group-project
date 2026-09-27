#include "Image_Class.h"
#include <iostream>
using namespace std;
void applyflip(Image &img) {
  int choice;
  cout << "1. Vertical flip, 2. Horizontal flip_" << endl;
  cin >> choice;

  if (choice == 1) {
    for (int _x = 0; _x < img.width / 2; _x++) {
      for (int _y = 0; _y < img.height; _y++) {
        for (int c = 0; c < 3; c++) {
          unsigned char color = img.getPixel(_x, _y, c);
          img.setPixel(_x, _y, c, img.getPixel(img.width - _x - 1, _y, c));
          img.setPixel(img.width - _x - 1, _y, c,
                       color); // funy how math can make my life both easier and
                               // harder at the same time ¯\_(ツ)_/¯
        }
      }
    }
  } else if (choice ==
             2) { // i love that it flip_worked first time so i just copy it add
                  // the choise and chage the y value insted of x and just be as
                  // lazy and as happy as possible (: lazyness + creativity =
                  // happiness + greatness (Eslam)🦥
    for (int _y = 0; _y < img.height / 2; _y++) {
      for (int _x = 0; _x < img.width; _x++) {
        for (int c = 0; c < 3; c++) {
          unsigned char color = img.getPixel(_x, _y, c);
          img.setPixel(_x, _y, c, img.getPixel(_x, img.height - _y - 1, c));
          img.setPixel(_x, img.height - _y - 1, c, color);
        }
      }
    }
  } else {
    cout << "Bruh🥀" << endl;
  }
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
int main() {
  Image img;
  if (img.loadNewImage("FellAsleep.jpg")) {
    applyflip(img);
    img.saveImage("FellAsleep_flip.jpg");
    cout << "hmmm, why did it work?" << endl;
  } else {
    cout << "hmmm, why it didn`t work?" << endl;
  }
  return 0;
}