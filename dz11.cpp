#include <iostream>

using namespace std;

class String {
private:
	static int Nstrings;
public:
	char* str;
public:
	String(int length)
	{	
		str = new char[length];
		Nstrings++;
	}
	String() : String(80) {}
	String(string s)
	{
		str = new char[s.length() + 1];
		strcpy_s(str, s.length() + 1, s.c_str());
		Nstrings++;
	}
	~String() {
		if (str != nullptr) {
			delete[] str;
		}
		Nstrings--;
	}
public:
	void EnterFromK() {
		string s;
		cout << "Enter str: ";
		cin >> s;
		str = new char[s.length() + 1];
		strcpy_s(str, s.length() + 1, s.c_str());
	}
	void Show() {
		cout << str << endl;
	}
	static int GetC() {
		return Nstrings;
	}
};
int String::Nstrings = 0;

struct PIB {
	string name;
	string surname;
	string fathersname;
};
class Human {
public:
	PIB* pib = new PIB;
public:
	Human(string name, string surname, string fathersname) {
		pib->name = name;
		pib->surname = surname;
		pib->fathersname = fathersname;
	}
	Human() : Human("nn", "nn", "nn") {}
	Human(string name, string surname) : Human(name, surname, "nn") {}
	Human(const Human &other)
	{
		this->pib = new PIB;
		this->pib->name = other.pib->name;
		this->pib->surname = other.pib->surname;
		this->pib->fathersname = other.pib->fathersname;
	}
	Human operator=(const Human& other) {
		delete pib;
		this->pib = new PIB;
		this->pib->name = other.pib->name;
		this->pib->surname = other.pib->surname;
		this->pib->fathersname = other.pib->fathersname;
		return *this;
	}
	~Human() {
		if (pib != nullptr) {
			delete pib;
		}
	}
public:
	void ShowInfo() {
		cout << "Name: " << pib->name << endl;
		cout << "Surname: " << pib->surname << endl;
		cout << "Fathersname: " << pib->fathersname << endl;
	}
};

class Flat {
public:
	int Chum = 0;
	Human* humans = new Human[0];
public:
	Flat(){}
	Flat(const Flat &other) {
		this->Chum = other.Chum;
		this->humans = new Human[Chum];
		for (int i = 0; i < Chum; i++) {
			this->humans[i] = other.humans[i];
		}
	}
	Flat operator=(const Flat& other) {
		delete[] humans;
		this->Chum = other.Chum;
		this->humans = new Human[Chum];
		for (int i = 0; i < Chum; i++) {
			this->humans[i] = other.humans[i];
		}
		return *this;
	}
	~Flat() {
		if (humans != nullptr) {
			delete[] humans;
		}
	}
public:
	void AddNew(Human human) {
		Human* newH = new Human[Chum + 1];
		for (int i = 0; i < Chum; i++) {
			newH[i] = humans[i];
		}
		newH[Chum] = human;
		delete[] humans;
		humans = newH;
		Chum++;
	}
	void DeleteOne(int h) {
		Human* newH = new Human[Chum - 1];
		for (int i = 0, j = 0; i < Chum; i++) {
			if (i != h) {
				newH[j++] = humans[i];
			}
		}
		delete[] humans;
		humans = newH;
		Chum--;
	}
};

class House {
public:
	int Cflats = 0;
	Flat* flats = new Flat[0];
public:
	House() {}
	House(const House& other) {
		this->Cflats = other.Cflats;
		this->flats = new Flat[Cflats];
		for (int i = 0; i < Cflats; i++) {
			this->flats[i] = other.flats[i];
		}
	}
	~House() {
		if (flats != nullptr) {
			delete[] flats;
		}
	}
public:
	void AddNew(Flat flat) {
		Flat* newF = new Flat[Cflats + 1];
		for (int i = 0; i < Cflats; i++) {
			newF[i] = flats[i];
		}
		newF[Cflats] = flat;
		delete[] flats;
		flats = newF;
		Cflats++;
	}
	void DeleteOne(int h) {
		Flat* newF = new Flat[Cflats - 1];
		for (int i = 0, j = 0; i < Cflats; i++) {
			if (i != h) newF[j++] = flats[i];
		}
		delete[] flats;
		flats = newF;
		Cflats--;
	}
};

int main() {
	Human h1("a", "o");
	Flat f2;
	f2.AddNew(h1);
	Flat f1(f2);
	f1.humans[0].ShowInfo();
	f2.humans[0].ShowInfo();

	House hh;
	hh.AddNew(f1);
	hh.AddNew(f2);
	hh.DeleteOne(0);
	hh.flats[0].humans[0].ShowInfo();
	return 0;
}
