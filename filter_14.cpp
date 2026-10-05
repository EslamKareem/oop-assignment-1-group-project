#include "Image_Class.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

Image tint(Image &img) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height-1; y++) {
    for (int x = 1; x < img.width-1; x++) {
      for (int c = 0; c < 3; c++) {
        int color = img.getPixel(x, y, c) * 0.7 + 128 * 0.3;
        image.setPixel(x, y, c, color);
      }
    }
  }
  return image;
}

Image noise(Image& img){
  Image image(img.width, img.height);

  for (int y = 1; y < img.height-1; y++) {
    for (int x = 1; x < img.width-1; x++) {
      int n = rand() % 81 - 40;
      for (int c = 0; c < 3; c++) {
        int color = img.getPixel(x, y, c) - n;
        color = max(0, min(255, color));
        image.setPixel(x, y, c, color);
      }
    }
  }
  return image;
}

Image scanline(Image& img){
  Image image(img.width, img.height);

  for (int y = 1; y < img.height-1; y++) {
    for (int x = 1; x < img.width-1; x++) {
      for (int c = 0; c < 3; c++) {
        int color = img.getPixel(x, y, c);
        if (y%3 == 0){
            color *= 0.7;
        }
        image.setPixel(x, y, c, color);
      }
    }
  }
  return image;
}




int main() {
  srand(time(NULL));
  Image img("luffy.jpg");

  Image image = tint(img);
  image.saveImage("luffy_tint.jpg");

  Image image2 = noise(image);
  image2.saveImage("luffy_noice.jpg");

  Image image3 = scanline(image2);
  image3.saveImage("luffy_sacnline.jpg");

}