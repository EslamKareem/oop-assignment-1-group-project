#include <iostream>
#include <vector>
#include "Image_Class.h"
using namespace std;

Image rotateImage(const Image& image) {
    int rows = image.height;
    int cols = image.width;

    Image rotated_image(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < 3; k++) {
                rotated_image(j, rows - 1 - i, k) = image(i, j, k);
            }
        }
    }

    return rotated_image;
}

int main(){
    Image image("luffy.jpg");
    Image rotated_image = rotateImage(image);
    rotated_image.saveImage("rotated_image.jpg");

}
            