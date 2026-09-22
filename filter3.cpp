#include "Image_class.h"
void invertImage(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                image.setPixel(i, j, k, 255 - image.getPixel(i, j, k)); 
            }
        }
    }   
}
int main() {
    Image myPicture("luffy.jpg");
    invertImage (myPicture);
    myPicture.saveImage("luffy_inverted.jpg");
    return 0;
} 