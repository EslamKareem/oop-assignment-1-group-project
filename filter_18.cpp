#include "Image_Class.h"
#include <iostream>
using namespace std;

int gray(Image& img, int x, int y){
    int r = img.getPixel(x, y, 0);
    int g = img.getPixel(x, y, 1);
    int b = img.getPixel(x, y, 2);
    return (r + g + b) / 3;
}

Image oilPainting(Image& img , int levels){
Image image(img.width, img.height);
int r = 4;

for (int y = r; y < img.height -r; y++){
for (int x = r; x < img.width - r; x++){
int count[16] = {0};
for (int dy = -r; dy <= r; dy++){
for (int dx = -r; dx <= r; dx++){
int g = gray(img, x+dx , y+dy);
int level = g * levels / 256;
count[level]++;
}
}
int best = 0;
for (int l = 1; l < levels; l++){
if (count[l] > count[best]) best = l;
}
int sr = 0, sg = 0, sb = 0, n = 0;
for (int dy = -r; dy <= r; dy++){
for (int dx = -r; dx <= r; dx++){
int g = gray(img, x+dx, y+dy);
if (g * levels/ 256 == best){
sr += img.getPixel(x+dx, y+dy, 0);
sg += img.getPixel(x+dx, y+dy, 1);
sb += img.getPixel(x+dx, y+dy, 2);
n++;
}
}
}
image.setPixel(x, y, 0, sr / n);
image.setPixel(x, y, 1, sg / n);
image.setPixel(x, y, 2, sb / n);
}
}
return image;
}

int main(){
Image img("luffy.jpg");
Image image = oilPainting(img, 8);
image.saveImage("luffy_oilpainting.jpg");

}