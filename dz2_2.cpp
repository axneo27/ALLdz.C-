#include <iostream>
using namespace std;

void ex1() {
	char s; 
	int o;
	cout << "Enter the symbol and orientation(1-h,2-v): " << endl;
	cin >> s >> o;
	switch (o)
	{
	case 1:
		for (int i = 0; i < 10; i++) {
			cout << s;
		}
		break;
	case 2:
		for (int i = 0; i < 10; i++) {
			cout << s << endl;
		}
		break;
	default:
		break;
	}
}

int ex2() {
	int take = 1;
	int sc = 0;
	int su = 0;
	do {
		int sc1, su1;
		cout << "\n" << "The " << take << " round" << endl;
		for (int i = 0; i < 2; i++) {
			srand(time(NULL));
			int s;
			cout << "The " << i + 1 << " take" << endl;
			cout << "Make a move by typing 1: ";
			cin >> s;
			if (s != 1) {
				return 1;
			}

			int ran = rand() % 6 + 1;
			cout << "Your number is " << ran << endl;
			int ran2 = rand() % 6 + 1;
			cout << "And the computer has " << ran2 << endl;
			sc += ran2;
			su += ran;
		}
		take += 1;
	} while (take <= 3);
	if (sc > su) {
		cout << "Computer Won!" << endl;
	}
	else if (su > sc) {
		cout << "User Won!" << endl;
	}
	cout << "Computer: " << sc << endl;
	cout << "Player: " << su << endl;
	return 0;
}

void ex3() {
	srand(time(NULL));
	int arr[10];
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	cout << "\nMAX: " << max << endl;
	cout << "MIN: " << min << endl;
}

void ex4() {
	int income_year[12], start, end;
	cout << "Enter the yearly income: " << endl;
	for (int i = 0; i < sizeof(income_year) / sizeof(income_year[0]); i++) {
		cin >> income_year[i];
	}
	cout << "Enter the diapazone(start, end): " << endl;
	cin >> start >> end;
	int max = income_year[start-1];
	int min = income_year[start-1];
	for (int i = start-1; i < end; i++) {
		if (income_year[i] > max) {
			max = income_year[i];
		}
		if (income_year[i] < min) {
			min = income_year[i];
		}
	}
	cout << "\nMAX: " << max << endl;
	cout << "MIN: " << min << endl;
}

void ex5() {
	srand(time(NULL));
	int arr[10] = { 1, 2, -3, 4, 5, -6, 7, 8, 9, 10 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int sminus = 0;
	int multi_2 = 1;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] < 0) {
			sminus += arr[i];
		}
		if (arr[i] % 2 == 0) {
			multi_2 *= arr[i];
		}
	}

	// maxmin
	int max = arr[0], max_i = 0;
	int min = arr[0], min_i = 0;
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_i = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			min_i = i;
		}
	}

	int startM = max_i, endM = min_i;
	if (max_i < min_i) {
		startM = max_i;
		endM = min_i;
	}

	int multi_maxMin = 1;
	bool hasElements = false;

	if (endM - startM > 1) { 
		hasElements = true; 
		for (int i = startM + 1; i < endM; i++) {
			multi_maxMin *= arr[i];
		}
	}

	if (!hasElements) {
		multi_maxMin = 0; 
	}


	// first and last minus
	bool f_f = false;
	int firstminus_i = -1;
	int lastminus_i = -1;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] < 0 && !f_f) {
			firstminus_i = i;
			f_f = true;
		}
		if (arr[i] < 0) {
			lastminus_i = i;
		}
	}

	int sumBetMinus = 0;
	if (firstminus_i != -1 && lastminus_i != -1 && firstminus_i < lastminus_i) {
		for (int i = firstminus_i + 1; i < lastminus_i; i++) {
			sumBetMinus += arr[i];
		}
	}

	cout << "Minus sum: " << sminus << endl;
	cout << "Multiplication product between max and min: " << multi_maxMin << endl;
	cout << "Multiplication product of even numbers: " << multi_2 << endl;
	cout << "Sum between the first and last minus: " << sumBetMinus << endl;
}

int main() {
	ex5();
	return 0;
}