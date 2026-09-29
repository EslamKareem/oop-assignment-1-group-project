// Assignment 1 Part 1
// those filters ware made by:
// Eslam Karim shawky - 20250814 - Filters 1,5
// Omar Yaser Sherif - 20250854 - Filters 2,6
// Mohammed kamal Gherbawi - 20253019 - Filters 3,7
// karem adel madi - 20253029 - Filters 4,8
// Sec 31,32

#include "Image_Class.h"
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
// karem adel madi - 20253029 - Filter 4 add frame
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
// karem adel madi - 20253029 - Filter 8 Resizing Image
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

// **The menu**

void ViewMenu() {
  cout << "Menu:" << endl;
  cout << "1. Gray Scale" << endl;
  cout << "2. Black and White" << endl;
  cout << "3. Invert" << endl;
  cout << "4. Adding Frame" << endl;
  cout << "5. Flip" << endl;
  cout << "6. Rotate" << endl;
  cout << "7. Lighten / Darken" << endl;
  cout << "8. Resize" << endl;
  cout << "9. Exit" << endl;
}

int BrightnessMenu() {
  int choice;
  cout << "Choose an option:\n";
  cout << "1. Lighten the image\n";
  cout << "2. Darken the image\n";
  cin >> choice;

  if (cin.fail()) {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid input. Please enter a number between 1 and 2." << endl;
    cin >> choice;
  }
  return choice;
}

int getChoice() {
  int choice;
  cin >> choice;
  if (cin.fail()) {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Invalid input. Please enter a number between 1 and 9." << endl;
    cin >> choice;
  }
  return choice;
}

int main() {
  string filename;

  int choice;
  do {
    ViewMenu();
    choice = getChoice();

    if (choice == 9) {
      cout << "Exiting the program." << endl;
      break;
    }

    cout << "Please enter the image filename: ";
    cin >> filename;
    Image image(filename);

    switch (choice) {
    case 1:
      Grayscale(image);
      break;
    case 2:
      blackAndWhite(image);
      break;
    case 3:
      invertImage(image);
      break;
    case 4:
      addframe(image);
      break;
    case 5:
      Flip(image);
      break;
    case 6:
      rotateImage(image);
      break;
    case 7:
      int brightnessChoice;
      brightnessChoice = BrightnessMenu();
      switch (brightnessChoice) {
      case 1:
        int lightenAmount;
        cout << "Enter the amount to lighten (0-100): ";
        cin >> lightenAmount;
        lightenImage(image, lightenAmount);
        break;
      case 2:
        int darkenAmount;
        cout << "Enter the amount to darken (0-100): ";
        cin >> darkenAmount;
        darkenImage(image, darkenAmount);
        break;
      default:
        cout << "Invalid choice. Please select 1 or 2." << endl;
      }
      break;
    case 8:
      resizeImage(image);
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }

    if (choice >= 1 && choice <= 8) {
      string outputFile;
      cout << "Save result as: ";
      cin >> outputFile;
      image.saveImage(outputFile);
      cout << "Saved to " << outputFile << endl;
    }
  } while (choice != 9);
}