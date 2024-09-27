#include <iostream>
using namespace std;

void ex1() {
	const int y = 5;
	const int x = 2;
	int arr[y][x] = {};

	int num;
	cout << "Enter the number: ";
	cin >> num;
	arr[0][0] = num;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if ((j != 0 && i == 0) || (j!=0 && i !=0)) {
				arr[i][j] = arr[i][j - 1] * 2;
			}
			else if (j==0 && i != 0) {
				arr[i][j] = arr[i - 1][x-1] * 2;
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}

void ex2() {
	const int y = 5;
	const int x = 3;
	int arr[y][x] = {};

	int num;
	cout << "Enter the number: ";
	cin >> num;
	arr[0][0] = num;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if ((j != 0 && i == 0) || (j != 0 && i != 0)) {
				arr[i][j] = arr[i][j - 1] + 1;
			}
			else if (j == 0 && i != 0) {
				arr[i][j] = arr[i - 1][x - 1] +1;
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}
void ex3() {
	const int y = 3;
	const int x = 6;
	int arr[y][x] = {1,2,0,4,5,3,
					4,5,3,9,0,1,
					2,2,2,2,2,2};

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int direction;
	int n;
	cout << "Enter the direction(1-up,2-down,3-left,4-right): ";
	cin >> direction;
	cout << "Enter the number of moves: ";
	cin >> n;
	switch (direction) {
	case 1:
		for (int k = 0; k < n; k++) {
			int temp[x] = {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (i == 0) {
						temp[j] = arr[y - 1][j];
						arr[y - 1][j] = arr[0][j];
					}
					else if (i == y - 1) {
						arr[i - 1][j] = temp[j];
					}
					else{
						arr[i - 1][j] = arr[i][j];

					}
				}
			}
		}
		break;
	case 2:
		for (int k = 0; k < n; k++) {
			int temp[x] = {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (i == 0) {
						temp[j] = arr[i][j];
						arr[i][j] = arr[y-1][j];
					}
					else if (i == y - 1) {
						arr[y - i][j] = temp[j];
					}
					else {
						arr[y - i][j] = arr[y-i-1][j];

					}
				}
			}
		}
		break;
	case 3:
		for (int k = 0; k < n; k++) {
			int temp[x] = {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (j == 0) {
						temp[i] = arr[i][x - 1];
						arr[i][x - 1] = arr[i][0];
					}
					else if (j == x - 1) {
						arr[i][j - 1] = temp[i];
					}
					else {
						arr[i][j - 1] = arr[i][j];
					}
				}
			}
		}
		break;
	case 4:
		for (int k = 0; k < n; k++) {
			int temp[x] = {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (j == 0) {
						temp[i] = arr[i][0];
						arr[i][0] = arr[i][x-1];
					}
					else if (j == x - 1) {
						arr[i][x - j] = temp[i];
					}
					else {
						arr[i][x - j] = arr[i][x - j - 1];
					}
				}
			}
		}
		break;
	default:
		break;
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
}

int main() {
	ex3();
	return 0;
}