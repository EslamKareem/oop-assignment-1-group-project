#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std;

Image skew(Image& img, int factor){
    Image image(img.width, img.height);

    for (int y = 1; y< img.height-1; y++){
        double angle = factor * M_PI / 180.0;
        int MaxShift = (int)((img.height - 1) * tan(angle));
        int shift = (int)(y * tan(angle)) - MaxShift / 2;
        for (int x = 1; x < img.width-1; x++){
            int src = x + shift;
            if(src < 0 || src >= img.width) continue;
            for ( int c = 0; c < 3; c++){
                image.setPixel(x, y, c, img.getPixel(src,y,c));
            }
        }
    }
    return image;
}

int main(){
    Image img("luffy.jpg"); 
    int x;
    cout << "enter the skew angle:";
    cin >> x ;
    Image image = skew(img,x);
    image.saveImage("luffy_skewed.jpg");
}