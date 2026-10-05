 #include <iostream>
#include "Image_class.h"
#include<string>
using namespace std;

void blurImage(Image& img, int radius)
{
    int Width = img.width;
    int Height = img.height;

    Image newImage = img;   

    for (int i = 0; i < Width; ++i)
    {
        for (int j = 0; j < Height; ++j)
        {
            long long redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;

            for (int x = -radius; x <= radius; ++x)
            {
                for (int y = -radius; y <= radius; ++y)
                {
                    int newX = i + x;
                    int newY = j + y;

                    if (newX >= 0 && newX < Width && newY >= 0 && newY < Height)
                    {
                        redSum   += newImage.getPixel(newX, newY, 0);
                        greenSum += newImage.getPixel(newX, newY, 1);
                        blueSum  += newImage.getPixel(newX, newY, 2);
                        count++;
                    }
                }
            }

            img.setPixel(i, j, 0, redSum / count);
            img.setPixel(i, j, 1, greenSum / count);
            img.setPixel(i, j, 2, blueSum / count);
        }
    }
}

int main()
{
     Image img;
    string name;
    cout << "Enter image name: ";
    cin >> name;
    img.loadNewImage(name);  



    int radius;
    cout << "Enter blur level (radius): ";
    cin >> radius;

    blurImage(img, radius);

    img.saveImage("blurred.jpg");
    return 0;
}