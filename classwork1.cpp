#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    srand(time(NULL));

    const int rows = 10;
    const int cols = 10;

    int arr[rows][cols];

    /*for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j <= i || i+j > 10-1) {
                cout << setw(1) << " " << " ";
            }
            else {
                cout << setw(1) << "*" << " ";
            }
        }
        cout << endl;
    }*/
    /*cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j <= i || i + j < 10 - 1) {
                cout << setw(1) << " " << " ";
            }
            else {
                cout << setw(1) << "*" << " ";
            }
        }
        cout << endl;
    }*/
    /*cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= i || i + j < 10 - 1) {
                cout << setw(1) << " " << " ";
            }
            else {
                cout << setw(1) << "*" << " ";
            }
        }
        cout << endl;
    }*/
    /*cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= i || i + j > 10 - 1) {
                cout << setw(1) << " " << " ";
            }
            else {
                cout << setw(1) << "*" << " ";
            }
        }
        cout << endl;
    }*/
    /*cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((j <= i && i + j > 10 - 1) || (j >= i && i + j < 10 - 1)) {
                cout << setw(1) << "*" << " ";
            }
            else {
                cout << setw(1) << " " << " ";
            }
        }
        cout << endl;
    }*/
    /*cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((j >= i && i + j > 10 - 1) || (j <= i && i + j < 10 - 1)) {
                cout << setw(1) << "*" << " ";
            }
            else {
                cout << setw(1) << " " << " ";
            }
        }
        cout << endl;
    }*/
    /*for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j >= i) {
                cout << setw(1) << "*" << " ";
            }
        }
        cout << endl;
    }*/
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((j >= i && i + j >= 10 - 1) || (j <= i && i + j < 10 - 1)) {
                cout << setw(1) << "*" << " ";
            }
            else {
                cout << setw(1) << " " << " ";
            }
        }
        cout << endl;
    }
}
