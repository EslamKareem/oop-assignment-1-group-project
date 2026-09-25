#include <iostream>
 #include "image_class.h"
using namespace std;

void addframe( Image&  img)
{
	cout << "welcome to our application ";
	cout << " enter frame thickness and color \n ";
	int frameWidth;
	cin >> frameWidth;
	int framecolorR = 255;
	int framecolorG = 255;
	int framecolorB = 255;

	int width = img.width;
	int height = img.height;


	for (int i = 0; i < height ;++i) 
	{

		for (int j = 0; j < width; ++j)
			if (i < frameWidth || i >= height - frameWidth || j < frameWidth || j >= width - frameWidth) 
			{
				img.setPixel(j, i, 0, framecolorR);
				img.setPixel(j, i, 1, framecolorG);
				img.setPixel(j, i, 2, framecolorB);
			}
			cout<<"frame added successfuiiy\n";     

	} 

	int main();  
	{
		string filename;
			cout << "Enter image filename to load ";
			cin >> filename;
			  
			  
			Image img(filename);




			addframe(img);

			


			string outputfilname;
			cout << "Enter outputfilename to save";


			cin >> outputfilname;
			img.saveImage(outputfilname);

			return 0;


	}


}