#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// WEEK 14
//1
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool ifDublicate(int arr[], int size, int x) {
    for (int i = x + 1; i < size; i++) {
        if (arr[i] == arr[x]) {
            return true;
        }
    }
    return false;
}

void e1() {
    int size1, size2;
    cout << "Enter the size for the A: ";
    cin >> size1;
    cout << "Enter the size for the B: ";
    cin >> size2;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    for (int i = 0; i < size1; i++) {
        cout << "Enter the " << i + 1 << " element for the A: ";
        cin >> arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        cout << "Enter the " << i + 1 << " element for the B: ";
        cin >> arr2[i];
    }

    int c = 0;
    for (int i = 0; i < size1; i++) {
        int c2 = 0;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                c2++;
                break;
            }
        }
        if (c2 == 0 && !ifDublicate(arr1, size1, i)) c++;
    }
    int* arr3 = new int[c];
    int h = 0;
    for (int i = 0; i < size1; i++) {
        int c2 = 0;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                c2++;
                break;
            }
        }
        if (c2 == 0) {
            arr3[h] = arr1[i];
            h++;
        }
    }

    print_array(arr1, size1);
    print_array(arr2, size2);
    print_array(arr3, c);
    cout << c << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

//2
void e2() {
    int size1, size2;
    cout << "Enter the size for the A: ";
    cin >> size1;
    cout << "Enter the size for the B: ";
    cin >> size2;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    for (int i = 0; i < size1; i++) {
        cout << "Enter the " << i + 1 << " element for the A: ";
        cin >> arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        cout << "Enter the " << i + 1 << " element for the B: ";
        cin >> arr2[i];
    }

    int c = 0;
    for (int i = 0; i < size1; i++) {
        int c2 = 0;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                c2++;
                break;
            }
        }
        if (c2 == 0 && !ifDublicate(arr1, size1, i)) c++;
    }

    for (int j = 0; j < size2; j++) {
        int c2 = 0;
        for (int i = 0; i < size1; i++) {
            if (arr1[i] == arr2[j]) {
                c2++;
                break;
            }
        }
        if (c2 == 0 && !ifDublicate(arr2, size2, j)) c++;
    }

    int* arr3 = new int[c];
    int h = 0;
    for (int i = 0; i < size1; i++) {
        int c2 = 0;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                c2++;
                break;
            }
        }
        if (c2 == 0) {
            arr3[h] = arr1[i];
            h++;
        }
    }

    for (int j = 0; j < size2; j++) {
        int c2 = 0;
        for (int i = 0; i < size1; i++) {
            if (arr1[i] == arr2[j]) {
                c2++;
                break;
            }
        }
        if (c2 == 0) {
            arr3[h] = arr2[j];
            h++;
        }
    }

    print_array(arr1, size1);
    print_array(arr2, size2);
    print_array(arr3, c);
    cout << c << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

}

//3
int* creArr(int size) {
    int* arr = new int[size];
    return arr;
}
int* initArr(int size) {
    int *arr = creArr(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> arr[i];
    }
    return arr;
}

void print_arrayD(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void delArr(int *arr) {
    delete[] arr;
}

int* addEle(int *arr, int &size, int ele) {
    size = size + 1;
    int* arr2 = creArr(size);
    for (int i = 0; i < size-1; i++) {
        arr2[i] = arr[i];
    }
    delete[] arr;
    arr2[size-1] = ele;
    return arr2;
}

void insertEle(int* arr, int ele, int index) {
    arr[index] = ele;
}

int* delEle(int* arr, int& size, int index) {
    size = size - 1;
    int* arr2 = creArr(size);
    int h = 0;
    for (int i = 0; i < size + 1; i++) {
        if (i != index) {
        arr2[h] = arr[i];
        h++;
        }
    }
    delete[] arr;
    return arr2;
}

//4
int* e4(int* arr, int& size) {
    int noProst = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < arr[i]; j++) {
            if (arr[i] % j == 0 && j != 1) {
                noProst++;
                break;
            }
        }
    }
    int* arr2 = new int[noProst];
    int h = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < arr[i]; j++) {
            if (arr[i] % j == 0 && j != 1) {
                arr2[h] = arr[i];
                h++;
                break;
            }
        }
    }
    print_array(arr2, noProst);
    return arr2;
}

//5
void e5(int * arr, int size) {
    int plus = 0, minus = 0, nul = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            minus++;
        }
        if (arr[i] > 0) {
            plus++;
        }
        if (arr[i] == 0) {
            nul++;
        }
    }
    int* aplus = new int[plus];
    int* aminus = new int[minus];
    int* anul = new int[nul];
    int h1 = 0, h2 = 0, h3 = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            aminus[h1] = arr[i];
            h1++;
        }
        if (arr[i] > 0) {
            aplus[h2] = arr[i];
            h2++;
        }
        if (arr[i] == 0) {
            anul[h3] = arr[i];
            h3++;
        }
    }
    print_array(aplus, plus);
    print_array(aminus, minus);
    print_array(anul, nul);
}

int main() {
    const int size = 5;
    int arr[size]{ 0,-1,2,3,4 };
    e5(arr, size);

    return 0;
}
