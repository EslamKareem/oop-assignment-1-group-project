#include <iostream>
#include "Image_Class.h"
#include "filter_4.cpp"
using namespace std;

void ViewMenu() {
    cout << "Menu:" << endl;
    cout << "1. Gray Scale" << endl;
    cout << "2. Black and White" << endl;
    cout << "3. Invert" << endl;
    cout << "4. Adding Frame" << endl;
    cout << "5. Flip" << endl;
    cout << "6. Rotate" << endl;
    cout << "7. Brightness" << endl;
    cout << "8. Resize" << endl;
    cout << "9. Save and Exit" << endl;
    cout << "10. Exit" << endl;
}



int main() {
    int choice;
    string filename;
    cout << "Please enter the image filename: ";
    cin >> filename;
    Image image(filename);

    do{
        ViewMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "You selected Filter 1." << endl;
                break;
            case 2:
                cout << "You selected Filter 2." << endl;
                break;
            case 3:
                cout << "You selected Filter 3." << endl;
                break;
            case 4:
                addframe(image);
                break;
            case 5:
                cout << "You selected Filter 5." << endl;
                break;
            case 6:
                cout << "You selected Filter 6." << endl;
                break;
            case 7:
                cout << "You selected Filter 7." << endl;
                break;
            case 8:
                cout << "You selected Filter 8." << endl;
                break;
            case 9:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 9);
}