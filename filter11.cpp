#include <iostream>
#include "Image_Class.h"
using namespace std;
void cropImage(Image& image){
    int x, y, W, H;
while (true) {
    cout << "Enter x (left): ";
    cin >> x;
    cout << "Enter y (top): ";
    cin >> y;
    cout << "Enter width W: ";
    cin>> W;
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
        cout << "Crop area exceeds image size("
    << image.width << "x" << image.height << ").\n";
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
int main() {
    Image myPicture("toy1.jpg");
    cropImage(myPicture);
    myPicture.saveImage("toy1_cropped.jpg");
    return 0;
}



             
