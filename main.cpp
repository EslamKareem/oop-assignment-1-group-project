#include <iostream>
using namespace std;

int main() {
    int choice;

    do{
        cout << "Menu:" << endl;
        cout << "1. Filter 1" << endl;
        cout << "2. Filter 2" << endl;
        cout << "3. Filter 3" << endl;
        cout << "4. Filter 4" << endl;
        cout << "5. Filter 5" << endl;
        cout << "6. Filter 6" << endl;
        cout << "7. Filter 7" << endl;
        cout << "8. Filter 8" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
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
                cout << "You selected Filter 4." << endl;
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