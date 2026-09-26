#include <iostream>
#include "Image_Class.h"
using namespace std;

void applyfilterGrayscale(Image &img) {
  for (int _y = 0; _y < img.height; _y++) {
    for (int _x = 0; _x < img.width; _x++) {
      unsigned char r = img.getPixel(_x, _y, 0);
      unsigned char g = img.getPixel(_x, _y, 1);
      unsigned char b = img.getPixel(_x, _y, 2);
      int grayscale = static_cast<int>((0.299 * r) + (0.587 * g) + (0.114 * b));
      // I could have used this "(pixel.r + pixel.g + pixel.b) / 3"
      // but it will look ugly so i did a bit of research (used google search ai
      // assistant while searching so i don`t waste a lot of time) and i found
      // this
      // "https://stackoverflow.com/questions/596216/formula-to-determine-brightness-of-rgb-color"
      // and i got an interasting forumla that makes it like the
      // photoshop grayscale and it`s called Luminosity equation so it looks
      // better now and more realistic (=
      img.setPixel(_x, _y, 0, grayscale);
      img.setPixel(_x, _y, 1, grayscale);
      img.setPixel(_x, _y, 2, grayscale);
    }
  }
}

void blackAndWhite(Image& image) {
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

void invertImage(Image &image) {
  for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
      for (int k = 0; k < 3; k++) {
        image.setPixel(i, j, k, 255 - image.getPixel(i, j, k));
      }
    }
  }
}

void addframe( Image&  img){
  cout << "welcome to our application ";
  int frameType;
  cout << "Choose frame type:\n";
  cout << "1. Simple frame || 2.Fancy frame\n";
  cin >> frameType;


  cout << " enter frame thickness and color \n ";
  int frameWidth;
  cin >> frameWidth;


  int framecolorR , framecolorG, framecolorB;
  cout<<" enter frame color in R G B , each value should be between 0 and 255\n";
  cin>>framecolorR>>framecolorG>>framecolorB;
	

  int width = img.width;
  int height = img.height;


    for (int i = 0; i < height ;++i) {
		for (int j = 0; j < width; ++j)
		if(frameType==1){
			if (i < frameWidth || i >= height - frameWidth || j < frameWidth || j >= width - frameWidth) {
				img.setPixel(j, i, 0, framecolorR);
				img.setPixel(j, i, 1, framecolorG);
				img.setPixel(j, i, 2, framecolorB);
			}
		}
		
		else if(frameType==2){
             if (i < frameWidth || i >= height - frameWidth || j < frameWidth || j >= width - frameWidth){
                img.setPixel(j, i, 0, framecolorR);
                img.setPixel(j, i, 1, framecolorG);
                img.setPixel(j, i, 2, framecolorB);
            }
        }
	} 

	cout<<"frame added successfully\n";
}

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