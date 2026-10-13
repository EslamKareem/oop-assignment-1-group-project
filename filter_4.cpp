#include <iostream>
#include"Image_Class.h"
#include<string>
using namespace std;

void addframe(Image &img)
{
cout<<"welcome to our frame adding function"<<endl;
int frameType;
cout<<"please choose frame type\n";
cout<<"1.simple frame || 2. fancy frame"<<endl;
cin>>frameType;

cout<<"enter farme thickness and color\n";
 int framethickness;
cin>>framethickness;

cout<<"enter color of frame in RGB each value should be between 0 and 255\n"; 
int framecolorR,framecolorG,framecolorB;
cin>>framecolorR>>framecolorG>>framecolorB;

int width=img.width;
int height=img.height;

for(int x=0; x<width; ++x)
{


 for(int y=0; y<height; ++y)
 {
   if(frameType==1)
   {
    if (x < framethickness || x >= width - framethickness || y < framethickness ||
    y >= height - framethickness)
    {
      
    img.setPixel(x,y,0,framecolorR);
    img.setPixel(x,y,1,framecolorG);
    img.setPixel(x,y,2,framecolorB);

    }
    
   }
  

else if(frameType==2)
   {
    if (x < framethickness || x >= width - framethickness || y < framethickness ||
    y >= height - framethickness)
     {
      
    img.setPixel(x,y,0,framecolorR);
    img.setPixel(x,y,1,framecolorG);
    img.setPixel(x,y,2,framecolorB);

    }
    else
    {
     int gap=5, line=3;
     int start=framethickness+gap;

     if (x >= start && x < width - start && y >= start && y < height - start)
     {
      int dx = min(x - start, (width - start - 1) - x);
      int dy = min(y - start, (height - start - 1) - y);

      if (min(dx, dy) < line)
      {
       img.setPixel(x,y,0,255);
       img.setPixel(x,y,1,255);
       img.setPixel(x,y,2,255);
      }
     }
    }
   }
 }
  
    


}

   cout<<"frame added successfully"<<endl;


}
int main() 
{
    string Picture;
    cout << "Enter image filename to load ";
    cin >> Picture;

    Image img(Picture);

    addframe(img);

    string outputfilname;
    cout << "Enter outputfilename to save";

    cin >> outputfilname;
    img.saveImage(outputfilname);

    return 0;
}