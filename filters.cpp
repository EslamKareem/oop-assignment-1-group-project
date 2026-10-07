#include "Image_Class.h"
#include <algorithm>
#include <iostream>
using namespace std;
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Eslam Karim shawky - 20250814 - Filter 1 Grayscale
void Grayscale(Image &img) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      unsigned char r = img.getPixel(x, y, 0);
      unsigned char g = img.getPixel(x, y, 1);
      unsigned char b = img.getPixel(x, y, 2);
      int grayscale = static_cast<int>((0.299 * r) + (0.587 * g) + (0.114 * b));
      // I could have used this "(pixel.r + pixel.g + pixel.b) / 3"
      // but it will look ugly so i did a bit of research (used google search ai
      // assistant while searching so i don`t waste a lot of time) and i found
      // this
      // "https://stackoverflow.com/questions/596216/formula-to-determine-brightness-of-rgb-color"
      // and i got an interasting forumla that makes it like the
      // photoshop grayscale and it`s called Luminosity equation so it looks
      // better now and more realistic (=
      img.setPixel(x, y, 0, grayscale);
      img.setPixel(x, y, 1, grayscale);
      img.setPixel(x, y, 2, grayscale);
    }
  }
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Omar Yaser Sherif - 20250854 - Filter 2 black and white
void blackAndWhite(Image &image) {
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
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Mohammed kamal Gherbawi - 20253019 - Filter 3 invert
void invertImage(Image &image) {
  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      for (int k = 0; k < 3; k++) {
        image.setPixel(i, j, k, 255 - image.getPixel(i, j, k));
      }
    }
  }
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Kareem adel madi - 20253029 - Filter 4 add frame
void addframe(Image &img) {
  cout << "welcome to our application ";
  int frameType;
  cout << "Choose frame type:\n";
  cout << "1. Simple frame || 2.Fancy frame\n";
  cin >> frameType;

  cout << " enter frame thickness and color \n ";
  int frameWidth;
  cin >> frameWidth;

  int framecolorR, framecolorG, framecolorB;
  cout << " enter frame color in R G B , each value should be between 0 and "
          "255\n";
  cin >> framecolorR >> framecolorG >> framecolorB;

  int width = img.width;
  int height = img.height;

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j)
      if (frameType == 1) {
        if (i < frameWidth || i >= height - frameWidth || j < frameWidth ||
            j >= width - frameWidth) {
          img.setPixel(j, i, 0, framecolorR);
          img.setPixel(j, i, 1, framecolorG);
          img.setPixel(j, i, 2, framecolorB);
        }
      }

      else if (frameType == 2) {
        if (i < frameWidth || i >= height - frameWidth || j < frameWidth ||
            j >= width - frameWidth) {
          img.setPixel(j, i, 0, framecolorR);
          img.setPixel(j, i, 1, framecolorG);
          img.setPixel(j, i, 2, framecolorB);
        }
      }
  }

  cout << "frame added successfully\n";
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Eslam Karim shawky - 20250814 - Filter 5 flip
void Flip(Image &img) {
  int choice;
  cout << "1. Vertical flip, 2. Horizontal flip_" << endl;
  cin >> choice;

  if (choice == 1) {
    for (int x = 0; x < img.width / 2; x++) {
      for (int y = 0; y < img.height; y++) {
        for (int c = 0; c < 3; c++) {
          unsigned char color = img.getPixel(x, y, c);
          img.setPixel(x, y, c, img.getPixel(img.width - x - 1, y, c));
          img.setPixel(img.width - x - 1, y, c,
                       color); // funy how math can make my life both easier and
                               // harder at the same time ¯\_(ツ)_/¯
        }
      }
    }
  } else if (choice ==
             2) { // i love that flipping worked first time so i just copy it
                  // add the choise and chage the y value insted of x and just
                  // be as lazy and as happy as possible (: lazyness +
                  // creativity = happiness + greatness (Eslam)🦥 i hate fixing
                  // the code and i hate not sleeping to fix the code and i hate
                  // when i have to do alot of search to find out why did the
                  // code work or why didn`t it at 3:27 am i just want to sleep
                  // like normal people why is it so hard?! 😭😭
    for (int y = 0; y < img.height / 2; y++) {
      for (int x = 0; x < img.width; x++) {
        for (int c = 0; c < 3; c++) {
          unsigned char color = img.getPixel(x, y, c);
          img.setPixel(x, y, c, img.getPixel(x, img.height - y - 1, c));
          img.setPixel(x, img.height - y - 1, c, color);
        }
      }
    }
  } else {
    cout << "Bruh🥀" << endl;
  }
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Omar Yaser Sherif - 20250854 - Filter 6 Rotate
Image rotateImage(Image &img) {
  int choice;
  cout << "1. Rotate 90 2. Rotate 270 3. Rotate 180" << endl;
  cin >> choice;

  if (choice == 1) {
    Image rotated_image(img.height, img.width);

    for (int i = 0; i < img.width; i++) {
      for (int j = 0; j < img.height; j++) {
        for (int k = 0; k < 3; k++) {
          rotated_image.setPixel(img.height - 1 - j, i, k,
                                 img.getPixel(i, j, k));
        }
      }
    }
    img = rotated_image;
  }

  else if (choice == 2) {
    Image rotated_image(img.height, img.width);

    for (int i = 0; i < img.width; i++) {
      for (int j = 0; j < img.height; j++) {
        for (int k = 0; k < 3; k++) {
          rotated_image.setPixel(j, img.width - 1 - i, k,
                                 img.getPixel(i, j, k));
        }
      }
    }
    img = rotated_image;
  }

  else if (choice == 3) {
    for (int i = 0; i < img.width / 2; i++) {
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
  } else {
    cout << "Invalid choice.Try again." << endl;
  }
  return img;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Mohammed kamal Gherbawi - 20253019 - Filter 7 Lighten/Darken
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
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
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
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Kareem adel madi - 20253029 - Filter 8 resize image
void resizeImage(Image &img) {

  int newHeight, newWidth;
  cout << "Enter new Height\n";
  cin >> newHeight;
  cout << "Enter new Width\n";
  cin >> newWidth;

  if (newWidth <= 0 || newHeight <= 0) {
    cout << "Invalid size\n";
    return;
  }

  Image newImage(newWidth, newHeight);

  double ratioX = (double)img.width / newWidth;
  double ratioY = (double)img.height / newHeight;

  for (int i = 0; i < newHeight; ++i) {
    for (int j = 0; j < newWidth; ++j) {
      int old_i = i * ratioY;
      int old_j = j * ratioX;

      if (old_i >= img.height)
        old_i = img.height - 1;
      if (old_j >= img.width)
        old_j = img.width - 1;

      for (int k = 0; k < 3; ++k) {

        newImage(j, i, k) = img(old_j, old_i, k);
      }
    }
  }

  img = newImage;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Eslam Karim shawky - 20250814 - Filter 9 Merge
void MergeImage(Image &img_1) {
  Image img_2;
  string filename_2;
  cout << "put the name of the 2nd image and the extension: ";
  cin >> filename_2;
  if (!img_2.loadNewImage(filename_2)) {
    cout << "that`s not working try again" << endl;
    return;
  } // for the logic of merging i`ll just use the easest way and use the If
    // statement
  // i`ll set both images on a common ground to skip the lomng steps ((lazyness
  // is the key to ceativity🦥))
  int comon_width;
  if (img_1.width < img_2.width) {
    comon_width = img_1.width;
  } else {
    comon_width = img_2.width;
  }
  int comon_height;
  if (img_1.height < img_2.height) {
    comon_height = img_1.height;
  } else {
    comon_height = img_2.height;
  }
  Image finalresult(comon_width, comon_height);
  for (int y = 0; y < comon_height; y++) {
    for (int x = 0; x < comon_width; x++) {
      for (int z = 0; z < 3;
           z++) { // blender my beloved how much did you teach me 🪉
        unsigned char pixel_1 = img_1.getPixel(x, y, z);
        unsigned char pixel_2 = img_2.getPixel(x, y, z);
        unsigned char merged_pixel = (pixel_1 + pixel_2) / 2;
        finalresult.setPixel(x, y, z, merged_pixel);
      }
    }
  }
  img_1 = finalresult;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Omar Yaser Sherif - 20250854 - Filter 10 edge detection
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

Image edgeImage(Image &img) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height - 1; y++) {
    for (int x = 1; x < img.width - 1; x++) {
      matrices n = columns(img, x, y);
      // -1 0 1
      // -2 0 2
      // -1 0 1

      int horizontal = -n.topLeft + n.topRight - (2 * n.left) + (2 * n.right) -
                       n.bottomLeft + n.bottomRight;

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

Image blurThenEdge(Image &img) {
  Image blurred = blurImage(img);
  Image edged = edgeImage(blurred);
  return edged;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Mohammed Kamal Gherbawi - 20253019 - Filter 11 crop image
void cropImage(Image &image) {
  int x, y, W, H;
  while (true) {
    cout << "Enter x (left): ";
    cin >> x;
    cout << "Enter y (top): ";
    cin >> y;
    cout << "Enter width W: ";
    cin >> W;
    cout << "Enter height H: ";
    cin >> H;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Numbers only.\n";
      continue;
    }
    if (x < 0 || y < 0 || W <= 0 || H <= 0) {
      cout << "Invalid values.\n";
      continue;
    }
    if (x + W > image.width || y + H > image.height) {
      cout << "Crop area exceeds image size(" << image.width << "x"
           << image.height << ").\n";
      continue;
    }
    break;
  }
  Image result(W, H);
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      for (int k = 0; k < 3; k++) {
        result(i, j, k) = image(x + i, y + j, k);
      }
    }
  }
  image = result;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Kareem adel madi - 20253029 - Filter 12 blur image
void blurImage(Image &img, int radius) {
  int Width = img.width;
  int Height = img.height;

  Image newImage = img;

  for (int i = 0; i < Width; ++i) {
    for (int j = 0; j < Height; ++j) {
      long long redSum = 0, greenSum = 0, blueSum = 0;
      int count = 0;

      for (int x = -radius; x <= radius; ++x) {
        for (int y = -radius; y <= radius; ++y) {
          int newX = i + x;
          int newY = j + y;

          if (newX >= 0 && newX < Width && newY >= 0 && newY < Height) {
            redSum += newImage.getPixel(newX, newY, 0);
            greenSum += newImage.getPixel(newX, newY, 1);
            blueSum += newImage.getPixel(newX, newY, 2);
            count++;
          }
        }
      }

      img.setPixel(i, j, 0, redSum / count);
      img.setPixel(i, j, 1, greenSum / count);
      img.setPixel(i, j, 2, blueSum / count);
    }
  }
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Eslam Karim shawky - 20250814 - Filter 13  better sun light

// sooo probaly youll notice that there is a a bit ((alot)) of simlarity between
// this and my grayscale filter, soo it`s probably because i just copied it and
// tryed to use the Luminosity equation
// however it didn`t work soo i just started changing the function and used the
// simpler method and like the graphic desigener i am ¯\_(ツ)_/¯ (duh), i
// started to tweek the values to make it look similar to the example pic in the
// pdf and believe it or not
// i burned it so much and it hurts my ego every time it`s not working🥀, so as
// much it hurts i found out that i need not just to change the values i also
// need to make new values so the code works and not burn the pic so my ego so
// it went from this (r * 1.3, g * 1.25, b * 0.9) to r = r * 2.4 ... to this int
// R = r * 1.3, and voala 👏 it does wprk and with a bit of tweeking to the
// green and red values it matched the example perfctly so now i can just sleep
// or die in pace you might be asking why i always mention sleeping , yeah i
// just love to code or fix issues or just make my caelestia look better when am
// tiyerd it have it`s own fun ngl also if i forget to mention "i use arch btw"
// 🍸️ check my github u know (=
void wanofixedlight(Image &img) {
  for (int y = 0; y < img.height; y++) {
    for (int x = 0; x < img.width; x++) {
      unsigned char r = img.getPixel(x, y, 0);
      unsigned char g = img.getPixel(x, y, 1);
      unsigned char b = img.getPixel(x, y, 2);
      // these values toak more than 12 attempts to work and more to fix the
      // whole function 🥀
      // they waren`t perfect after all but you know what they say
      //"if it`s working don't touch it"😇 , i`ll just call it a day here
      int R = r * 1.28;
      int G = g * 1.25;
      int B = b * 0.9;
      if (R > 255)
        R = 255;
      if (G > 255)
        G = 255;
      if (B > 255)
        B = 255;
      img.setPixel(x, y, 0, R);
      img.setPixel(x, y, 1, G);
      img.setPixel(x, y, 2, B);
    }
  }
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Omar Yaser Sherif - 20250854 - Filter 14 tint
Image tint(Image &img) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height - 1; y++) {
    for (int x = 1; x < img.width - 1; x++) {
      for (int c = 0; c < 3; c++) {
        int color = img.getPixel(x, y, c) * 0.7 + 128 * 0.3;
        image.setPixel(x, y, c, color);
      }
    }
  }
  return image;
}

Image noise(Image &img) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height - 1; y++) {
    for (int x = 1; x < img.width - 1; x++) {
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

Image scanline(Image &img) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height - 1; y++) {
    for (int x = 1; x < img.width - 1; x++) {
      for (int c = 0; c < 3; c++) {
        int color = img.getPixel(x, y, c);
        if (y % 3 == 0) {
          color *= 0.7;
        }
        image.setPixel(x, y, c, color);
      }
    }
  }
  return image;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Mohammed Kamal Gherbawi - 20253019 - Filter 15 purple color
int main() {
  Image image("luffy.jpg");

  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      int r = image(i, j, 0) * 1.2;
      int g = image(i, j, 1) * 0.7;
      int b = image(i, j, 2) * 1.3;

      image(i, j, 0) = min(255, r);
      image(i, j, 1) = min(255, g);
      image(i, j, 2) = min(255, b);
    }
  }
  image.saveImage("luffy purple.jpg");
  return 0;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// Kareem adel madi - 20253029 - Filter 16 infrared
int infrared() {
  Image image("Nar.jpg");
  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      int r = image(i, j, 0);
      int g = image(i, j, 1);
      int b = image(i, j, 2);

      int ir = g * 1.2 + r * 0.3 - b * 0.2;
      ir = max(0, min(255, ir));

      image(i, j, 0) = 255;
      image(i, j, 1) = ir;
      image(i, j, 2) = ir;
    }
  }
  image.saveImage("Nar red.jpg");
  return 0;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//
// bonos filters
Image skew(Image &img, int factor) {
  Image image(img.width, img.height);

  for (int y = 1; y < img.height - 1; y++) {
    double angle = factor * M_PI / 180.0;
    int MaxShift = (int)((img.height - 1) * tan(angle));
    int shift = (int)(y * tan(angle)) - MaxShift / 2;
    for (int x = 1; x < img.width - 1; x++) {
      int src = x + shift;
      if (src < 0 || src >= img.width)
        continue;
      for (int c = 0; c < 3; c++) {
        image.setPixel(x, y, c, img.getPixel(src, y, c));
      }
    }
  }
  return image;
}
//***//***//***//***//***//***////***//***//***//***//***//***////***//***//***//***//***//***//