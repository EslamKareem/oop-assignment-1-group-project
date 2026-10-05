#include <iostream>
#include "Image_Class.h"
#include <algorithm>
using namespace std;
int main() {
    Image image("Nar.jpg");
for (int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
        int r = image(i, j, 0);
        int g = image(i, j, 1);
        int b = image(i, j, 2);

        int ir = g*1.2 + r*0.3 - b*0.2;
        ir = max(0, min(255, ir));

        image (i,j,0) = 255;
        image (i,j,1) = ir;
        image (i,j,2) = ir;
    }
}
image.saveImage("Nar red.jpg");
return 0;
}
