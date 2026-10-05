#include "Image_Class.h"
#include <iostream>
using namespace std;

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

int main() {
  Image img;
  if (img.loadNewImage("Wano.jpg")) {
    wanofixedlight(img);
    img.saveImage("Wanocolored.jpg");
    cout << "yea, it do work" << endl;
  } else {
    cout << "nuh uh" << endl;
  }
  return 0;
}