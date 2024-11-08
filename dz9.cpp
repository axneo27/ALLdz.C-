#include <iostream>
#include <string>
using namespace std;

int strToInt(string n) {
	int num = 0;
	bool neg = false;
	if (n[0] == '-') {
		neg = true;
		n = n.substr(1);
	}
	if (n[0] == '+') {
		n = n.substr(1);
	}

	for (int i = 0; i < n.length(); i++) {
		if (n[i] < (int)'0' || n[i] > (int)'9') {
			return -1111111; 
		}
		num = num * 10 + (n[i] - (int)'0');
	}

	return neg ? -num : num;
}

int nu1(string num) {
	string n1 = "";
	for (int i = 0; num[i] != '\0'; i++) {
		if (num[i] == '+' || num[i] == '-') {
			if (i == 0) {
				n1 += num[i];
			}
			for (int j = 0; j < i; j++) {
				n1 += num[j];
			}
		}
	}
	return strToInt(n1);
}

int initI(string num) {
	string n2 = "";
	for (int i = 0; num[i] != '\0'; i++) {
		if (num[i] == '+' || num[i] == '-' && i != 0) {
			for (int j = i; num[j] != '\0' && num[j] != 'i'; j++) {
				n2 += num[j];
			}
		}
	}
	return strToInt(n2);
}

struct Complex {
	string num;
	int n1;
	int i;
	Complex(string n) {
		num = n;
		n1 = nu1(num);
		i = initI(num);
	}

};

Complex Add(Complex num1, Complex num2) {
	int n3 = num1.n1 + num2.n1;
	int i3 = num1.i + num2.i;
	string nC;
	if (i3 >= 0) {
		nC = to_string(n3)+'+'+ to_string(i3) + 'i';
	}
	return Complex(nC);
}

Complex Subtract(Complex num1, Complex num2) {
	int n3 = num1.n1 - num2.n1;
	int i3 = num1.i - num2.i;
	string nC;
	if (i3 >= 0) {
		nC = to_string(n3) + '+' + to_string(i3) + 'i';
	}
	else {
		nC = to_string(n3) + to_string(i3) + 'i';
	}
	return Complex(nC);
}

Complex Multiply(Complex num1, Complex num2) {
	int n3 = num1.n1*num2.n1 + num1.i*num2.i;
	int i3 = num1.n1 * num2.i + num1.i * num2.n1;
	string nC;
	if (i3 >= 0) {
		nC = to_string(n3) + '+' + to_string(i3) + 'i';
	}
	else {
		nC = to_string(n3) + to_string(i3) + 'i';
	}
	return Complex(nC);
}

Complex Divide(Complex num1, Complex num2) {
	float n3 = (num1.n1 * num2.n1 + num1.i * num2.i)/(pow(num2.n1, 2) + pow(num2.i, 2));
	float i3 = (-num1.n1 * num2.i + num1.i * num2.n1)/(pow(num2.n1, 2) + pow(num2.i, 2));
	string nC;
	if (i3 >= 0) {
		nC = to_string(n3) + '+' + to_string(i3) + 'i';
	}
	else {
		nC = to_string(n3) + to_string(i3) + 'i';
	}
	return Complex(nC);
}
//2
struct Auto {
	float length;
	float clearance;
	float Vengine;
	float Pengine;
	float Dwheels;
	string colour;
	string gearbox;
};

void Init(Auto& a) {
	cout << "Enter length: ";
	cin >> a.length;
	cout << "Enter clearance: ";
	cin >> a.clearance;
	cout << "Enter engine volume: ";
	cin >> a.Vengine;
	cout << "Enter engine power: ";
	cin >> a.Pengine;
	cout << "Enter wheels diameter: ";
	cin >> a.Dwheels;
	cout << "Enter gearbox(manual, automatic): ";
	cin >> a.gearbox;
}

void Show(Auto a) {
	cout << "Length: " << a.length << endl;
	cout << "Clearance: " << a.clearance << endl;
	cout << "Engine volume: " << a.Vengine << endl;
	cout << "Engine power: " << a.Pengine << endl;
	cout << "Wheels diameter: " << a.Dwheels << endl;
	cout << "Gearbox: " << a.gearbox << endl;
}

void FindThing(Auto a) {
	cout << "Enter parameter to find: " << endl;
	int s;
	cout << "1 - Length\n2 - Clearance\n3 - Engine volume\n4 - Engine power\n5 - Wheels diameter\n6 - Gearbox: ";
	cin >> s;
	switch (s)
	{
	case 1:
		cout << a.length << endl;
	case 2:
		cout << a.clearance << endl;
	case 3:
		cout << a.Vengine << endl;
	case 4:
		cout << a.Pengine << endl;
	case 5:
		cout << a.Dwheels << endl;
	case 6:
		cout << a.gearbox << endl;
	default:
		cout << "Invalid command" << endl;
		break;
	}
}

int main() {

	return 0;
}
