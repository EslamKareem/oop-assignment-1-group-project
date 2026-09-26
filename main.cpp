#include <iostream>
#include "filters.cpp"
#include "Image_Class.h"
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
    cout << "9. Exit" << endl;
}

int getChoice() {
    int choice;
    cin >> choice;
    if (cin.fail()){
        cin.clear(); 
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between 1 and 9." << endl;
        cin >> choice;
    }
    return choice;
}



int main() {
    string filename;
    
    int choice;
    do{
        ViewMenu();
        choice = getChoice();

        cout << "Please enter the image filename: ";
        cin >> filename;
        Image image(filename);

        switch(choice) {
            case 1:
                applyfilterGrayscale(image);
                break;
            case 2:
                blackAndWhite(image);
                break;
            case 3:
                invertImage(image);
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

        if (choice >= 1 && choice <= 8) {
            string outputFile;
            cout << "Save result as: ";
            cin >> outputFile;
            image.saveImage(outputFile);
            cout << "Saved to " << outputFile << endl;
        }
    } while(choice != 9);
}