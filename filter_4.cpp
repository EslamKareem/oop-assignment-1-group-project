#include <iostream>
 #include "image_class.h"
 #include<string>
using namespace std;
void addframe( Image&  img)
{
	cout << "welcome to our application ";
  int frameType;
  cout << "Choose frame type:\n";
  cout << "1. Simple frame || 2.Fancy frame\n";
  cin >> frameType;


	cout << " enter frame thickness and color \n ";
	int frameWidth;
	cin >> frameWidth;


	int framecolorR , framecolorG, framecolorB;
	cout<<" enter frame color in R G B , each value should be between 0 and 255\n";
	cin>>framecolorR>>framecolorG>>framecolorB;
	

	int width = img.width;
	int height = img.height;


	for (int i = 0; i < height ;++i) 
	{

		for (int j = 0; j < width; ++j)
		if(frameType==1)
		{
			if (i < frameWidth || i >= height - frameWidth || j < frameWidth || j >= width - frameWidth) 
			{
				img.setPixel(j, i, 0, framecolorR);
				img.setPixel(j, i, 1, framecolorG);
				img.setPixel(j, i, 2, framecolorB);
			}
		}
		
		else if(frameType==2)
{
    if (i < frameWidth || i >= height - frameWidth || j < frameWidth || j >= width - frameWidth)
    {
        img.setPixel(j, i, 0, framecolorR);
        img.setPixel(j, i, 1, framecolorG);
        img.setPixel(j, i, 2, framecolorB);
    }
}



	} 

	cout<<"frame added successfully\n";
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



