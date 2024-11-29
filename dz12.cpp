#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
	int numerator;
	int denominator;
public:
	Fraction(int top, int bottom) : numerator(top), denominator(bottom) {};
	int BiggestDivid(int a, int b);
	Fraction operator+(Fraction other);
	Fraction operator-(Fraction other);
	Fraction operator*(Fraction other);
	Fraction operator/(Fraction other);
	~Fraction() {  };
};
int Fraction::BiggestDivid(int a, int b) {
	if (a == b) {
		return b;
	}
	else if (b != 0 && a != 0) {
		if (a > b) return BiggestDivid(a % b, b);
		return BiggestDivid(a, b % a);
	}
	return a + b;
}
Fraction Fraction::operator+(Fraction other) {
	int nN1 = this->numerator * other.denominator;
	int nN2 = this->denominator * other.numerator;
	int nD = this->denominator * other.denominator;
	int BiggestDiv = BiggestDivid(nN1 + nN2, nD);
	return Fraction((nN1 + nN2) / BiggestDiv, nD / BiggestDiv);
}
Fraction Fraction::operator-(Fraction other) {
	int nN1 = this->numerator * other.denominator;
	int nN2 = this->denominator * other.numerator;
	int nD = this->denominator * other.denominator;
	int BiggestDiv = BiggestDivid(nN1 - nN2, nD);
	return Fraction((nN1 - nN2) / BiggestDiv, nD / BiggestDiv);
}
Fraction Fraction::operator*(Fraction other) {
	int BiggestDiv = BiggestDivid(this->numerator * other.numerator, this->denominator * other.denominator);
	return Fraction((this->numerator * other.numerator)/BiggestDiv, (this->denominator * other.denominator) / BiggestDiv);
}
Fraction Fraction::operator/(Fraction other) {
	int BiggestDiv = BiggestDivid(this->numerator*other.denominator, this->denominator*other.numerator);
	return Fraction((this->numerator * other.denominator) / BiggestDiv, (this->denominator * other.numerator) / BiggestDiv);
}
void printFraction(Fraction f) {
	cout << f.numerator << "/" << f.denominator << endl;
}

class Complex {
private:
	int n1;
	int i;
public:
	Complex(int n, int i) : n1(n), i(i) {};
	friend Complex operator+(Complex num1, Complex num2);
	friend Complex operator-(Complex num1, Complex num2);
	friend Complex operator*(Complex num1, Complex num2);
	friend Complex operator/(Complex num1, Complex num2);
	void printComplex() {
		cout << "real: " << this->n1 << endl;
		cout << "imaginary: " << this->i << endl;
	}
};

Complex operator+(Complex num1, Complex num2) {
	int n3 = num1.n1 + num2.n1;
	int i3 = num1.i + num2.i;
	return Complex(n3,i3);
}

Complex operator-(Complex num1, Complex num2) {
	int n3 = num1.n1 - num2.n1;
	int i3 = num1.i - num2.i;
	return Complex(n3,i3);
}

Complex operator*(Complex num1, Complex num2) {
	int n3 = num1.n1 * num2.n1 + num1.i * num2.i;
	int i3 = num1.n1 * num2.i + num1.i * num2.n1;
	return Complex(n3,i3);
}

Complex operator/(Complex num1, Complex num2) {
	float n3 = (num1.n1 * num2.n1 + num1.i * num2.i)/(pow(num2.n1, 2) + pow(num2.i, 2));
	float i3 = (-num1.n1 * num2.i + num1.i * num2.n1)/(pow(num2.n1, 2) + pow(num2.i, 2));
	return Complex(n3,i3);
}

class OverCoat {
public:
	string overcoat;
	int cost;
public:
	OverCoat(string coatType, int c): overcoat(coatType), cost(c){}
	OverCoat() : overcoat("no coat"), cost(0){}
	OverCoat(string coatType) : OverCoat(coatType, 0){}
	OverCoat(int c) : OverCoat("no coat", c){}

	OverCoat& operator=(const OverCoat& other) {
		this->overcoat = other.overcoat;
		this->cost = other.cost;
		return *this;
	}
	bool operator==(const OverCoat& other) const {
		return this->overcoat == other.overcoat;
	}
	int operator>(const OverCoat& other)const {
		if (this->overcoat == other.overcoat) {
			if (this->cost > other.cost) return 1;
			return 0;
		}
		return -1;
	}
	int operator<(const OverCoat& other)const {
		if (this->overcoat == other.overcoat) {
			if (this->cost < other.cost) return 1;
			return 0;
		}
		return -1;
	}
};

class Flat {
public:
	int S;
	int cost;
public:
	Flat(int area, int c) : S(area), cost(c){}
	Flat() : Flat(0,0){}
	explicit Flat(int area) : Flat(area, area*1000){}

	Flat& operator=(const Flat& other) {
		this->S = other.S;
		this->cost = other.cost;
		return *this;
	}
	bool operator>(const Flat& other)const {
		return this->cost > other.cost;
	}
	bool operator<(const Flat& other)const {
		return this->cost < other.cost;
	}
	bool operator==(const Flat& other) const {
		return other.S == this->S;
	}

};

int main() {

}
