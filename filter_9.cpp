#include "Image_Class.h"
#include <iostream>
using namespace std;

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
int main() {
  Image img;
  if (img.loadNewImage("cry.jpg")) {
    MergeImage(img);
    img.saveImage("merged_image.jpg");
    cout << "you`ll survive tonight😌" << endl;
  } else {
    cout << "you`ll die tonight no img 1💣️" << endl;
  }
  return 0;
}