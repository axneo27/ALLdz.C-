#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//WEEK 17

void print2darr(int **parr, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << parr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void del2darr(int** parr, int x) {
	for (int i = 0; i < x; i++) delete[] parr[i];
	delete[] parr;
}

int** e1(int** parr, int x, int y, int col[], int pos) {
	int** parr2 = new int* [x]; 
	for (int i = 0; i < x; i++) {
		parr2[i] = new int[y + 1];
	}
	for (int i = 0; i < x; i++) {
		bool crossed = false;
		for (int j = 0; j < y + 1; j++) {
			if (j == pos) {
				parr2[i][j] = col[i];
				crossed = true;
			}
			else if (crossed) {
				parr2[i][j] = parr[i][j - 1];
			}
			else {
				parr2[i][j] = parr[i][j];
			}
		}
	}

	return parr2; 
}


int** e2(int** parr, int x, int y, int pos) {
	int* onear = new int[y - 1];
	int** parr2 = new int* [x];
	for (int i = 0; i < x; i++) parr2[i] = onear;
	for (int i = 0; i < x; i++) {
		bool crossed = false;
		for (int j = 0; j < y; j++) {
			if (j == pos) {
				crossed = true;
			}
			else if (crossed) {
				parr2[i][j - 1] = parr[i][j];
			}
			else parr2[i][j] = parr[i][j];
		}
	}
	return parr2;
}

void init2darr(int** parr, int xx, int yy) {
	srand(time(NULL));
	for (int i = 0; i < xx; i++) {
		for (int j = 0; j < yy; j++) {
			parr[i][j] = rand() % 50;
		}
	}
}

void e3(int **parr, int y, int x) {
	print2darr(parr, y, x);
	int direction;
	int n;
	cout << "Enter the direction(1-up,2-down,3-left,4-right): ";
	cin >> direction;
	cout << "Enter the number of moves: ";
	cin >> n;
	switch (direction) {
	case 1:
		for (int k = 0; k < n; k++) {
			int *temp = new int[x]{};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (i == 0) {
						temp[j] = parr[y - 1][j];
						parr[y - 1][j] = parr[0][j];
					}
					else if (i == y - 1) {
						parr[i - 1][j] = temp[j];
					}
					else{
						parr[i - 1][j] = parr[i][j];

					}
				}
			}
			delete[] temp;
		}
		break;
	case 2:
		for (int k = 0; k < n; k++) {
			int* temp = new int[x] {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (i == 0) {
						temp[j] = parr[i][j];
						parr[i][j] = parr[y-1][j];
					}
					else if (i == y - 1) {
						parr[y - i][j] = temp[j];
					}
					else {
						parr[y - i][j] = parr[y-i-1][j];

					}
				}
			}
			delete[] temp;
		}
		break;
	case 3:
		for (int k = 0; k < n; k++) {
			int* temp = new int[x] {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (j == 0) {
						temp[i] = parr[i][x - 1];
						parr[i][x - 1] = parr[i][0];
					}
					else if (j == x - 1) {
						parr[i][j - 1] = temp[i];
					}
					else {
						parr[i][j - 1] = parr[i][j];
					}
				}
			}
			delete[] temp;
		}
		break;
	case 4:
		for (int k = 0; k < n; k++) {
			int* temp = new int[x] {};
			for (int i = 0; i < y; i++) {
				for (int j = 0; j < x; j++) {
					if (j == 0) {
						temp[i] = parr[i][0];
						parr[i][0] = parr[i][x-1];
					}
					else if (j == x - 1) {
						parr[i][x - j] = temp[i];
					}
					else {
						parr[i][x - j] = parr[i][x - j - 1];
					}
				}
			}
			delete[] temp;
		}
		break;
	default:
		break;
	}
	print2darr(parr, y, x);
	
}

// 2 part

int** transponn(int **parr, int x, int y) {
	int** parr2 = new int* [y];
	for (int i = 0; i < y; i++) parr2[i] = new int[x];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			parr2[j][i] = parr[i][j];
		}
	}
	return parr2;
}

void showData(char*** namephone, int n) {
	cout << "--------------------------" << "\n";
	for (int i = 0; i < n; i++) {
		cout << i+1 << " Name: " << namephone[i][0] << endl;
		cout << i+1 << " Phone: " << namephone[i][1] << endl;
	}
	cout << "--------------------------" << "\n";
}

int SearchByName(char*** namephone, int n, char name[]) {
	for (int i = 0; i < n; i++) {
		if (namephone[i][0] == name){
			return i + 1;
		}
	}
	return -1;
}

int SearchByPhone(char*** namephone, int n, char phone[]) {
	for (int i = 0; i < n; i++) {
		if (namephone[i][1] == phone) {
			return i + 1;
		}
	}
	return -1;
}

char*** InsertData(char*** namephone, int &n, char name[], char phone[]) {
	char*** NamePhone = new char** [n + 1];
	//re
	for (int i = 0; i < n; i++) {
		NamePhone[i] = new char* [2];
		NamePhone[i][0] = new char[50];
		NamePhone[i][1] = new char[50];
		strcpy_s(NamePhone[i][0], 50, namephone[i][0]);
		strcpy_s(NamePhone[i][1], 50, namephone[i][1]);
	}
	NamePhone[n] = new char* [2];
	NamePhone[n][0] = new char[50];
	NamePhone[n][1] = new char[50];
	strcpy_s(NamePhone[n][0], 50, name);
	strcpy_s(NamePhone[n][1], 50, phone);

	for (int i = 0; i < n; i++) {
		delete[] namephone[i][0];
		delete[] namephone[i][1];
		delete[] namephone[i];
	}
	delete[] namephone;
	n = n + 1;

	return NamePhone;
}

void changeData(char*** namephone, int pos, char name[], char phone[]) {
	namephone[pos - 1][0] = name;
	namephone[pos - 1][1] = phone;
}

int ser() {
	int p = 1;
	const int size = 50;

	char*** NamePhone = new char** [p];
	NamePhone[0] = new char* [2];
	for (int j = 0; j < 2; j++) NamePhone[0][j] = new char[size];

	strcpy_s(NamePhone[0][0], size, "Olexiy");
	strcpy_s(NamePhone[0][1], size, "999999");
	showData(NamePhone, p);

	while (1) {
		int action;
		cout << endl;
		cout << "Enter action: " << endl;
		cout << "1 - Search by name;" << endl;
		cout << "2 - Search by phone;" << endl;
		cout << "3 - Insert data;" << endl;
		cout << "4 - Change data.;" << "\n";
		cout << "5 - Quit :" << "\n";
		cin >> action;

		char phone[size];
		char name[size]; 
		int pos;
		switch (action) {
		case 1:
			cout << "Enter name: ";
			cin >> name;
			cout << SearchByName(NamePhone, p, name) << " Name: " << NamePhone[SearchByName(NamePhone, p, name) -1][0] << endl;
			cout << SearchByName(NamePhone, p, name) << " Phone: " << NamePhone[SearchByName(NamePhone, p, name) -1][1] << endl;
			break;
		case 2:
			cout << "Enter phone: ";
			cin >> phone;
			cout << SearchByPhone(NamePhone, p, phone) << " Name: " << NamePhone[SearchByPhone(NamePhone, p, phone) - 1][0] << endl;
			cout << SearchByPhone(NamePhone, p, phone) << " Phone: " << NamePhone[SearchByPhone(NamePhone, p, phone) - 1][1] << endl;
			break;
		case 3:
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter phone: ";
			cin >> phone;
			NamePhone = InsertData(NamePhone, p, name, phone);
			showData(NamePhone, p);
			break;
		case 4:
			cout << "Enter pos: ";
			cin >> pos;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter phone: ";
			cin >> phone;
			changeData(NamePhone, pos, name, phone);
			showData(NamePhone, p);
			break;
		case 5:
			return 1;
			break;
		default:
			cout << "Wrong command" << endl;
			for (int i = 0; i < p; i++) {
				for (int j = 0; j < 2; j++) {
					delete[] NamePhone[i][j];
				}
				delete[] NamePhone[i];
			}
			delete[] NamePhone;
			return 1;
			break;
		}
	}

	
}

int main() {
	
}
	
