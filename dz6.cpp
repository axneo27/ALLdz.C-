#include <iostream>
using namespace std;

//WEEK 15
//1

int Action(int *a, int *b, int sizea, int sizeb, int (*funcptr)(int *a, int *b, int sizea, int sizeb)) {
  return funcptr(a, b, sizea, sizeb);
}

int max_(int* a, int* b, int sizea, int sizeb) {
	int max = a[0];
	for (int i = 0; i < sizea + sizeb; i++) {
		if (i < sizea) {
			if (a[i] > max) max = a[i];
		}
		else if (i >= sizea) {
			if (b[i - sizea] > max) max = b[i - sizea];
		}
	}
	return max;
}

int min_(int* a, int* b, int sizea, int sizeb) {
	int min = a[0];
	for (int i = 0; i < sizea + sizeb; i++) {
		if (i < sizea) {
			if (a[i] < min) min = a[i];
		}
		else if (i >= sizea) {
			if (b[i - sizea] < min) min = b[i - sizea];
		}
	}
	return min;
}

int avg_(int* a, int* b, int sizea, int sizeb) {
	int s = 0;
	for (int i = 0; i < sizea; i++) s += a[i];
	for (int i = 0; i < sizeb; i++) s += b[i];
	return s/(sizea+sizeb);
}

int e1Main() {
	int a[]{ 0,1,2,3,4 };
	int b[]{ 5,20,3,5,1,70};
	int sizea = sizeof(a) / sizeof(a[0]);
	int sizeb = sizeof(b) / sizeof(b[0]);

	string action;
	cout << "Enter action: ";
	cin >> action;

	int res = -1;
	cout << "Result: ";
	if (action == "max") res = Action(a, b, sizea, sizeb, max_);
	else if (action == "min") res = Action(a, b, sizea, sizeb, min_);
	else if (action == "avg") res = Action(a, b, sizea, sizeb, avg_);
	cout << res << endl;
	return res;
}

//CHAR[]

void e1(char *a, int num) {
	for (int i = num; a[i] != '\0'; i++) {
		a[i] = a[i + 1];
	}
}

void e2(char* a, char s) {
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] == s) {
			for (int j = i; a[j] != '\0'; j++) {
				a[j] = a[j + 1];
			}
		}
	}
}

void e3(char* a, char s, int n) {
	a[n] = s;
}

void e4() {
	char a[100];
	cout << "Enter string: ";
	cin >> a;

	for (int i = 0; a[i] != '\0'; i++) if (a[i] == '.') a[i] = '!';
	cout << endl;
	cout << "Result: ";
	cout << a;
}

void e5() {
	char a[100], s;
	cout << "Enter string: ";
	cin >> a;
	cout << endl;
	cout << "Enter symbol: ";
	cin >> s;
	int c = 0;
	for (int i = 0; a[i] != '\0'; i++) if (a[i] == s) c++;
	cout << endl;
	cout << c;
}

void e6() {
	char a[100], s;
	cout << "Enter string: ";
	cin >> a;

	int n = 0;
	int l = 0;
	int o = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		a[i] = tolower(a[i]);
		if ((int)a[i] >= 48 && (int)a[i] <= 57) n++;
		if ((int)a[i] >= 97 && (int)a[i] <= 122) l++;
		else if (!((int)a[i] >= 97 && (int)a[i] <= 122) && !((int)a[i] >= 48 && (int)a[i] <= 57)) o++;
	}
	cout << "Numbers: " << n << endl;
	cout << "Letters: " << l << endl;
	cout << "Other: " << o << endl;
}

int main() {
	
	return 0;
}
