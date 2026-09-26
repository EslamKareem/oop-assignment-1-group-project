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
    cout << "7. Lighten / Darken" << endl;
    cout << "8. Resize" << endl;
    cout << "9. Exit" << endl;
}

int BrightnessMenu() {
     int choice;
     cout << "Choose an option:\n";
     cout << "1. Lighten the image\n";
     cout << "2. Darken the image\n";
     cin >> choice;

     if (cin.fail()){
        cin.clear(); 
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a number between 1 and 2." << endl;
        cin >> choice;
    }
     return choice;
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
                int brightnessChoice;
                brightnessChoice = BrightnessMenu();
                switch (brightnessChoice) {
                    case 1:
                        int lightenAmount;
                        cout << "Enter the amount to lighten (0-100): ";
                        cin >> lightenAmount;
                        lightenImage(image, lightenAmount);
                        break;
                    case 2:
                        int darkenAmount;
                        cout << "Enter the amount to darken (0-100): ";
                        cin >> darkenAmount;
                        darkenImage(image, darkenAmount);
                        break;
                    default:
                        cout << "Invalid choice. Please select 1 or 2." << endl;
                }
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