#include <iostream>
using namespace std;

// HOMEWORK 1
void fivehundred() {
	int a;
	cout << "Enter a: " << endl;
	cin >> a;

	int sum = 0;
	for (int i = a; i <= 500; i++) {
		sum += i;
	}
	cout << "Sum from " << a << " to 500 is: " << sum << endl;
}

void power() {
	int x, y;
	cout << "Enter x and y: " << endl;
	cin >> x >> y;

	int c = y;
	if (y < 0) {
		c *= -1;
	}

	float res = 1.0;
	for (int i = 0; i < c; i++) {
		res *= x;
	}

	if (y < 0) {
		res = 1 / res;
	}
	cout << "Result: " << res << endl;
}

void avg() {

	int s = 0;
	for (int i = 1; i <= 1000; i++) {
		s += i;
	}
	cout << "Average: " << s / 1000.0 << endl;
}

void multi20() {
	int a;
	cout << "Enter a: " << endl;
	cin >> a;

	int product = 1;
	for (int i = a; i <= 20; i++) {
		product *= i;
	}
	cout << "Multiplication product from " << a << " to 20 is: " << product << endl;
}

void multi_table() {
	int a;
	cout << "Enter a: " << endl;
	cin >> a;

	for (int i = 1; i <= 10; i++) {
		cout << a << " * " << i << " = " << a * i << endl;
	}
}

// HOMEWORK 2

void count1() {

	for (int nm = 100; nm <= 999; nm++) {
		int n1 = 0, n2 = 0, n3 = 0;
		n1 = nm / 100;
		n2 = (nm / 10) % 10;
		n3 = nm % 10;

		if ((n1 == n2 || n1 == n3 || n2 == n3) && !(n1 == n2 && n2 == n3)) {
			cout << nm << endl;
		}
	}
}

void count2() {
	for (int nm = 100; nm <= 999; nm++) {
		int n1 = 0, n2 = 0, n3 = 0;
		n1 = nm / 100;
		n2 = (nm / 10) % 10;
		n3 = nm % 10;

		if (n1 != n2 && n1 != n3 && n2 != n3) {
			cout << nm << endl;
		}
	}
}

void del36() {
	int n;
	cout << "Enter the number: " << endl;
	cin >> n;

	int fN = n;
	int ndigits = 0;
	do {
		fN /= 10;
		ndigits += 1;
	} while (fN >= 1);

	int newn = 0;
	int c = 1;
	int s = 1;
	for (int i = 0; i < ndigits; i++) {
		int d = (n / c) % 10;
		if (d != 3 && d != 6) {
			newn += d*s;
			s *= 10;
		}
		c *= 10;
	}
	cout << newn << endl;
}

void ex5() {
	int a;
	cout << "Enter the number: " << endl;
	cin >> a;

	for (int b = 1; b <= a; b++) {
		if (a % (b*b) == 0) {
			cout << b << endl;
		}
		if (a % (b * b * b) != 0) {
			cout << b << endl;
		}
	}
}

void ex6() {
	int a;
	cout << "Enter the number: " << endl;
	cin >> a;

	for (int b = 1; b <= a; b++) {
		if (a % b == 0) {
			cout << b << endl;
		}
	}
}

void ex7() {
	int a, b;
	cout << "Enter two numbers: " << endl;
	cin >> a >> b;

	int end;
	if (a >= b)
	{
		end = a;
	}
	else {
		end = b;
	}
	for (int i = 1; i <= end; i++) {
		if (a % i == 0 && b % i == 0) {
			cout << i << endl;
		}
	}
}

// Logichni operatory

void charachter() {
	char user_input;
	cout << "Enter a charachter: " << endl;
	cin >> user_input;

	int something = (int)user_input;
	if (something >= 48 && something <= 57) {
		cout << "That is a number" << endl;
	}
	else if ((something >= 65 && something <= 90) || (something >= 97 && something <= 122)) {
		cout << "That is a letter" << endl;
	}
	else if ((something >= 58 && something <= 63) || (something >= 33 && something <= 46)) {
		cout << "That is a punctuation sign" << endl;
	}
	else {
		cout << "That is something other" << endl;
	}
}

void operat() {
	enum operatory {VODAFON = 19, KYIVSTAR = 20, LIFE = 100, OPERATOR_OLEXIYA = 1000};

	int Ochoice, Ochoice2, time;
	cout << "Enter the time of the conversation (minutes): " << endl;
	cin >> time;
	cout << "Enter your operator:\n1-Vodafon (19$/min)\n2-Kyivstar (20$/min)\n3-Life (100$/min)\n4-Operator_Olexiya (1000$/min) " << endl;
	cin >> Ochoice;
	cout << "Enter the other operator:\n1-Vodafon (19$/min)\n2-Kyivstar (20$/min)\n3-Life (100$/min)\n4-Operator_Olexiya (1000$/min) " << endl;
	cin >> Ochoice2;

	switch (Ochoice) {
	case 1:
		Ochoice = VODAFON;
		break;
	case 2:
		Ochoice = KYIVSTAR;
		break;
	case 3:
		Ochoice = LIFE;
		break;
	case 4:
		Ochoice = OPERATOR_OLEXIYA;
		break;
	default:
		cout << "Wrong operation" << endl;
		break;
	}
	switch (Ochoice2) {
	case 1:
		Ochoice2 = VODAFON;
		break;
	case 2:
		Ochoice2 = KYIVSTAR;
		break;
	case 3:
		Ochoice2 = LIFE;
		break;
	case 4:
		Ochoice2 = OPERATOR_OLEXIYA;
		break;
	default:
		cout << "Wrong operation" << endl;
		break;
	}
	cout << "Price: " << time * ((Ochoice+Ochoice2)/2) << "$" << endl;

}

void VASYA() {
	int op, salary, linesOfCode, delays;
	const int salaryFor100Lines = 50;
	const int fineForDelays = 20;

	cout << "Choose operation:\n1-find lines of code\n2-find number of delays\n3-find the salary : " << endl;
	cin >> op;

	switch (op) {
	case 1:
		cout << "Enter the needed salary and number of delays : " << endl;
		cin >> salary >> delays;

		linesOfCode =2* (salary + (delays * 20));

		cout << "Needed number of lines of code: " << linesOfCode << endl;
		break;
	case 2:
		cout << "Enter the needed salary and number of lines : " << endl;
		cin >> salary >> linesOfCode;

		delays = (linesOfCode/2 - salary)/20.0;
		if (delays < 0) {
			cout << "HEHE that doesn`t work like that" << endl;
		}
		else {
			cout << "Possible number of delays: " << delays << endl;
		}
		break;

	case 3:
		cout << "Enter the lines of code and number of delays : " << endl;
		cin >> linesOfCode >> delays;

		salary = linesOfCode/2 - (20*delays);

		if (salary <= 0) {
			cout << "Your debt is: " << abs(salary) << "$" << endl;
		}
		else {
			cout << "Salary: " << salary << "$" << endl;
		}
		break;
	default:
		cout << "Invalid command" << endl;
		break;
	}

}

int main() {

	VASYA();

	return 0;
}