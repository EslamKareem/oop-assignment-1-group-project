#include "Image_Class.h"
#include <iostream>
using namespace std;
void applyfilterGrayscale(Image &img) {
  for (int _y = 0; _y < img.height; _y++) {
    for (int _x = 0; _x < img.width; _x++) {
      unsigned char r = img.getPixel(_x, _y, 0);
      unsigned char g = img.getPixel(_x, _y, 1);
      unsigned char b = img.getPixel(_x, _y, 2);
      int grayscale = static_cast<int>(
          (0.299 * r) + (0.587 * g) +
          (0.114 *
           b));
// I could have used this "(pixel.r + pixel.g + pixel.b) / 3"
// but it will look ugly so i did a bit of research (used google search ai
// assistant while searching so i don`t waste a lot of time) and i found
// this "https://stackoverflow.com/questions/596216/formula-to-determine-brightness-of-rgb-color"
// and i got an interasting forumla that makes it like the
// photoshop grayscale and it`s called Luminosity equation so it looks
// better now and more realistic (=
      img.setPixel(_x, _y, 0, grayscale);
      img.setPixel(_x, _y, 1, grayscale);
      img.setPixel(_x, _y, 2, grayscale);
    }
  }
}
// well after not working that i didn`t notice why it kept giving me compiler
// errors it was just this int grayscale more spicific this (int) yeah am an
// idiot, anyways it was an easy fix if i did do some search i found a funny
// soulotion and it was this "static_cast<int>" and tada , so i guess i lerned
// somthing and that is I AM STUPID (:
// i feel like i should have known that but i guess i was just too lazy to do
// some research and i really need to sleep, but now i know (:
int main() {
  Image img;
  if (img.loadNewImage("FellAsleep.jpg")) {
    applyfilterGrayscale(img);
    img.saveImage("FellAsleep_gray.jpg");
    cout << "yeaa, i can sleep now" << endl;
  } else {
    cout << "nooo, not again" << endl;
  }
  return 0;
}
