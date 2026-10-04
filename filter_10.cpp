#include "Image_Class.h"
#include <cmath>
#include <iostream>
using namespace std;

int gray(Image &img, int x, int y) {
  unsigned int avg = 0;
  for (int c = 0; c < 3; c++) {
    avg += img.getPixel(x, y, c);
  }
  return avg /= 3;
}

struct matrices {
  int topLeft, left, bottomLeft;
  int above, below;
  int topRight, right, bottomRight;
};

matrices columns(Image &img, int x, int y) {
  matrices m;

  // left column
  m.topLeft = gray(img, x - 1, y - 1);
  m.left = gray(img, x - 1, y);
  m.bottomLeft = gray(img, x - 1, y + 1);

  // above and below
  m.above = gray(img, x, y - 1);
  m.below = gray(img, x, y + 1);

  // right column
  m.topRight = gray(img, x + 1, y - 1);
  m.right = gray(img, x + 1, y);
  m.bottomRight = gray(img, x + 1, y + 1);
  return m;
}

Image blurImage(Image &img) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height - 1; y++) {
    for (int x = 1; x < img.width - 1; x++) {
      matrices n = columns(img, x, y);
      // 1 1 1
      // 1 1 1
      // 1 1 1
      int sum = n.topLeft + n.left + n.bottomLeft + n.above + n.below +
                n.topRight + n.right + n.bottomRight;
      unsigned char blurValue = (unsigned char)(sum / 9);

      for (int c = 0; c < 3; c++) {
        image.setPixel(x, y, c, blurValue);
      }
    }
  }
    return image;
}

Image edgeImage(Image & img) {
    Image image(img.width, img.height);

    for (int y = 1; y < img.height - 1; y++) {
      for (int x = 1; x < img.width - 1; x++) {
        matrices n = columns(img, x, y);
        // -1 0 1
        // -2 0 2
        // -1 0 1

        int horizontal = -n.topLeft + n.topRight - (2 * n.left) +
                         (2 * n.right) - n.bottomLeft + n.bottomRight;

        // 1 2 1
        // 0 0 0
        // -1 -2 -1

        int vertical = n.topLeft + (2 * n.above) + n.topRight - n.bottomLeft -
                       (2 * n.below) - n.bottomRight;

        double gradientMagnitude =
            sqrt(double((horizontal * horizontal) + (vertical * vertical)));

        double edgeThreshold = 200;
        unsigned char edgeValue = gradientMagnitude > edgeThreshold ? 0 : 255;

        for (int c = 0; c < 3; c++) {
          image.setPixel(x, y, c, edgeValue);
        }
      }
    }

    return image;
}

Image blurThenEdge(Image& img){
  Image blurred = blurImage(img);
  Image edged = edgeImage(blurred);
  return edged;
}

int main() {
    Image img("luffy.jpg");
    Image image = blurThenEdge(img);
    image.saveImage("luffy_edged.jpg");
}