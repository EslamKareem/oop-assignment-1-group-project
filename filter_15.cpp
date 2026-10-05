#include <iostream>
#include "Image_Class.h"
using namespace std;
int main() {
    Image image("luffy.jpg");
    
for(int i = 0; i < image.width; i++) {
    for (int j = 0; j < image.height; j++) {
        int r = image(i, j, 0)*1.2;
        int g = image(i, j, 1)*0.7;
        int b = image(i, j, 2)*1.3;

        image (i,j,0) = min(255,r);
        image (i,j,1) = min(255,g);
        image (i,j,2) = min(255,b);
    }
}
image.saveImage("luffy purple.jpg");
return 0;
}


