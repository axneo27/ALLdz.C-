#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

// FUNCTIONS
void Sortt(int arr[], int n);
void Sortt(double arr[], int n);

int E1_power(int x, int y) {

	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

int E2(int x, int y) {

	int sum = 0;
	for (int i = x + 1; i < y; i++) {
		sum += i;
	}
	return sum;

}

void E3(int x, int y) {

	for (int i = x; i <= y; i++) {
		int dil_sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				dil_sum += j;
			}
		}
		if (dil_sum == i) {
			cout << i << endl;
		}
	}

}

void E4Card(string card) {
	if (card == "Hearts") {
		cout << u8"\u2665" << endl;
	}
	else if (card == "Diamond") {
		cout << u8"\u2666" << endl;
	}
	else if (card == "Club") {
		cout << u8"\u2663" << endl;
	}
	else if (card == "Sprade") {
		cout << u8"\u2660" << endl;
	}
}

bool EX5happy(int x) {
	int c = x;
	int cc = 0;
	do {
		c /= 10;
		cc += 1;
	} while (c >= 1);
	if (cc != 6) {
		cout << "Must be 6";
		return false;
	}

	int first3[] = { 0,0,0 };
	int lst3[] = { 0,0,0 };
	int d1 = 100000;
	int d2 = 1;

	int eq = 0;
	for (int i = 0; i < 3; i++) {
		first3[i] = (x / d1) % 10;
		lst3[i] = (x / d2) % 10;
		d1 /= 10;
		d2 *= 10;

		if (first3[i] == lst3[i]) {
			eq += 1;
		}
	}
	if (eq == 3) {
		return true;
	}
	return false;
}

//FUNCTIONS. ARRAYS INTO FUNCTIONS

int Linear(int arr[], int size, int key) {
	
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;

}

int Binary(int arr[], int x, int low, int high) {
	
	if (high >= low) {
		int mid = low + ((high - low) / 2);
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] > x) {
			high = mid - 1;
			return Binary(arr, x, low, high);
		}
		else if (arr[mid] < x) {
			low = mid + 1;
			return Binary(arr, x, low, high);
		}
	}
	return -1;
}

int bintoten(char binary[]) {
	int size = strlen(binary);

	int result = 0;
	int y = 1;
	for (int i = size - 1; i >= 0; i--) {
		if (binary[i] == '1') {
			result += y;
		}
		y *= 2;
	}
	return result;
}

//FUNCTIONS.PASSING ARRAYS TO FUNCTIONS

bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	case 2: return isLeap(year) ? 29 : 28;
	default: return 0;
	}
}

int dif_days(int y1, int m1, int d1, int y2, int m2, int d2) {
	int result = 0;
	if (y1 > y2 || (y1 == y2 && (m1 > m2 || (m1 == m2 && d1 > d2)))) {
		swap(y1, y2);
		swap(m1, m2);
		swap(d1, d2);
	}
	for (int year = y1; year < y2 - 1; year++) {
		result += isLeap(year) ? 366 : 365;
	}

	for (int m = m1 + 1; m <= 12; m++) {
		result += daysInMonth(m, y1);
	}
	result -= d1;

	for (int m = 1; m <= m2; m++) {
		result += daysInMonth(m, y2);
	}
	result += d2;

	return result;
}

int ser(int arr[], int size) {

	int s = 0;
	for (int i = 0; i < size; i++) {
		s += arr[i];
	}
	return s / size;
}

void DodVidNul(int arr[], int size) {
	int dod = 0;
	int vid = 0;
	int nul = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			dod += 1;
		}
		else if (arr[i] < 0) {
			vid += 1;
		}
		else if (arr[i] == 0) {
			nul += 1;
		}
	}
	cout << "N > 0: " << dod << endl;
	cout << "N < 0: " << vid << endl;
	cout << "N = 0: " << nul << endl;
}

// OVERLOAD, RECURSION
const int m = 3;
void Mtx(int arr[m][m]) {
	srand(time(NULL));
	int c = 0;
	int gol[m] = {};
	int max = gol[0];
	int min;
	cout << "Unsorted: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 100;
			cout << arr[i][j] << " ";
			if (i == j) {
				gol[i] = arr[i][j];
				if (gol[i] > max) {
					max = gol[i];
				}
				if (i == 0) {
					min = gol[0];
				}
				else if (gol[i] < min) {
					min = gol[i];
				}
			}
			c++;
		}
		cout << endl;
	}
	cout << endl;
	cout << "Sorted: " << endl;
	for (int i = 0; i < m; i++) {
		int ar[m] = {};
		for (int j = 0; j < m; j++) {
			ar[j] = arr[i][j];
		}
		Sortt(ar, m);
		for (int j = 0; j < m; j++) {
			cout << ar[j] << " ";
		}
		cout << endl;
	}
	
}

void Mtx(double arr[m][m]) {
	srand(time(NULL));
	int c = 0;
	double gol[m] = {};
	double max = gol[0];
	double min;
	cout << "Unsorted: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 100;
			cout << arr[i][j] << " ";
			if (i == j) {
				gol[i] = arr[i][j];
				if (gol[i] > max) {
					max = gol[i];
				}
				if (i == 0) {
					min = gol[0];
				}
				else if (gol[i] < min) {
					min = gol[i];
				}
			}
			c++;
		}
		cout << endl;
	}
	cout << endl;
	cout << "Sorted: " << endl;
	for (int i = 0; i < m; i++) {
		double ar[m] = {};
		for (int j = 0; j < m; j++) {
			ar[j] = arr[i][j];
		}
		Sortt(ar, m);
		for (int j = 0; j < m; j++) {
			cout << ar[j] << " ";
		}
		cout << endl;
	}

}

void Mtx(char arr[m][m]) { // think max, min and sort doesnt make sense
	srand(time(NULL));
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = (char)(rand() % 256);
			cout << arr[i][j] << " ";
			c++;
		}
		cout << endl;
	}

}

void Sortt(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
		int k = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > k) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = k;
	}
}

void Sortt(double arr[], int n) {
	for (int i = 1; i < n; ++i) {
		double k = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > k) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = k;
	}
}

int BiggestDivid(int a, int b) {
	if (a == 0) {
		return b;
	}
	else if (b != 0 && a != 0) {
		if (a > b) return BiggestDivid(a%b,b);
		return BiggestDivid(a, b % a);
	}
	return a + b;

}

int BullsAndCows(int randnum, int num = 1) {

	if (num == 1) {
		int n;
		cout << "Start the game: ";
		cin >> n;
		if (n > 9999 || n < 1000) {
			cout << "Please dont crash anything" << endl;
			return BullsAndCows(randnum);
		}
		if (n == randnum) {
			cout << "WOOOOW the first try. Congrats!" << endl;
			return 1;
		}
		else {
			int bulls = 0;
			int cows = 0;

			int h1 = 1;
			for (int i = 0; i < 4; i++) {
				int h2 = 1;
				int dig_rand = (randnum / h1) % 10;
				h1 *= 10;

				for (int j = 0; j < 4; j++) {
					int dig_num = (n / h2) % 10;
					h2 *= 10;

					if (i == j) {
						if (dig_num == dig_rand) {
							cows ++;
							bulls++;
						}
					}
					else {
						if (dig_num == dig_rand) {
							bulls ++;
						}
					}
				}
			}
			cout << "Bulls: " << bulls << endl;
			cout << "Cows: " << cows << endl;
			return BullsAndCows(randnum, num+1);
		}
	}
	else {
		int n;
		cout << "Make another attempt: ";
		cin >> n;
		if (n > 9999 || n < 1000) {
			cout << "Please dont crash anything" << endl;
			return BullsAndCows(randnum, num);
		}
		if (n == randnum) {
			cout << "Congrats!" << endl;
			cout << "You have done it in " << num << " tries." << endl;
			return 1;
		}

		int bulls = 0;
		int cows = 0;

		int h1 = 1;
		for (int i = 0; i < 4; i++) {
			int h2 = 1;
			int dig_rand = (randnum / h1) % 10; 
			h1 *= 10;

			for (int j = 0; j < 4; j++) {
				int dig_num = (n / h2) % 10;
				h2 *= 10;

				if (i == j) {
					if (dig_num == dig_rand) {
						cows ++;
						bulls++;
					}
				}
				else {
					if (dig_num == dig_rand) {
						bulls ++;
					}
				}
			}
		}
		cout << "Bulls: " << bulls << endl;
		cout << "Cows: " << cows << endl;
		return BullsAndCows(randnum, num + 1);
	}
}

int main() {

	srand(time(NULL));
	int randnum = rand() % 9000 + 1000;
	BullsAndCows(randnum);
	return 0;
}
