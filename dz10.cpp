#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Fraction {
public:
	int numerator;
	int denominator;
public:
	Fraction(int top, int bottom) : numerator(top), denominator(bottom) {};
	int BiggestDivid(int a, int b);
	Fraction Add(Fraction other);
	Fraction Subtract(Fraction other);
	Fraction Multiply(Fraction other);
	Fraction Divide(Fraction other);
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
Fraction Fraction::Add(Fraction other) {
	int nN1 = this->numerator * other.denominator;
	int nN2 = this->denominator * other.numerator;
	int nD = this->denominator * other.denominator;
	int BiggestDiv = BiggestDivid(nN1 + nN2, nD);
	return Fraction((nN1 + nN2) / BiggestDiv, nD / BiggestDiv);
}
Fraction Fraction::Subtract(Fraction other) {
	int nN1 = this->numerator * other.denominator;
	int nN2 = this->denominator * other.numerator;
	int nD = this->denominator * other.denominator;
	int BiggestDiv = BiggestDivid(nN1 - nN2, nD);
	return Fraction((nN1 - nN2) / BiggestDiv, nD / BiggestDiv);
}
Fraction Fraction::Multiply(Fraction other) {
	int BiggestDiv = BiggestDivid(this->numerator * other.numerator, this->denominator * other.denominator);
	return Fraction((this->numerator * other.numerator)/BiggestDiv, (this->denominator * other.denominator) / BiggestDiv);
}
Fraction Fraction::Divide(Fraction other) {
	int BiggestDiv = BiggestDivid(this->numerator*other.denominator, this->denominator*other.numerator);
	return Fraction((this->numerator * other.denominator) / BiggestDiv, (this->denominator * other.numerator) / BiggestDiv);
}
void printFraction(Fraction f) {
	cout << f.numerator << "/" << f.denominator << endl;
}

//2
struct PIB {
	string name;
	string surname;
	string fathersname;
};
struct Phone {
	string home_phone;
	string job_phone;
	string mobile_phone;
};
class Contact {
public:
	PIB pib;
	Phone phone;
	string ADDinfo = "no info";
	Contact(string name, string surname, string fname, string home_phone, string job_phone, string mobile_phone, string addinfo);
	Contact(string name, string surname, string fname, string phonee, string addinfo);
	Contact() {
		pib.name = "n";
		pib.surname = "n";
		pib.fathersname = "n";
		phone.home_phone = "n"; 
		phone.job_phone = "n";
		phone.mobile_phone = "n";
	}
};
Contact::Contact(string name, string surname, string fname, string home_phone, string job_phone, string mobile_phone, string addinfo) {
	pib.name = name;
	pib.surname = surname;
	pib.fathersname = fname;
	phone.home_phone = home_phone;
	phone.job_phone = job_phone;
	phone.mobile_phone = mobile_phone;
	ADDinfo = addinfo;
}
Contact::Contact(string name, string surname, string fname, string phonee, string addinfo) {
	pib.name = name;
	pib.surname = surname;
	pib.fathersname = fname;
	phone.home_phone = phonee;
	phone.job_phone = phonee;
	phone.mobile_phone = phonee;
	ADDinfo = addinfo;
}
class PhoneBook {
private:
	int counter = 0;
	const int nOfData = 7;
	Contact *contacts = nullptr;
public:

	~PhoneBook() {
		delete[] contacts;
	}

	inline void AddNew(Contact c);
	inline void DeleteOne(int n);
	inline void ShowOne(Contact c);
	inline void ShowAll();
	inline int SearchbyPIB(PIB pib);
	inline void WriteFile();
	inline void ReadFile();
};
void PhoneBook::AddNew(Contact c) {
	Contact* nConts = new Contact[counter + 1];
	for (int i = 0; i < counter; i++) {
		nConts[i] = contacts[i];
	}
	nConts[counter] = c;
	delete[] contacts;
	counter++;
	contacts = nConts;
}
void PhoneBook::DeleteOne(int n) {
	Contact* nConts = new Contact[counter - 1];
	for (int i = 0; i < counter; i++) {
		if (i < n) nConts[i] = contacts[i];
		else if (i > n) nConts[i - 1] = contacts[i];
	}
	delete[] contacts;
	counter--;
	contacts = nConts;
}
void PhoneBook::ShowOne(Contact c) {
	cout << "PIB: " << c.pib.name << " " << c.pib.surname << " " << c.pib.fathersname << endl;
	cout << "Home phone: " << c.phone.home_phone << endl;
	cout << "Job phone: " << c.phone.job_phone << endl;
	cout << "Mobile phone: " << c.phone.mobile_phone << endl;
	cout << "Additional info: " << c.ADDinfo << endl;
}
void PhoneBook::ShowAll() {
	for (int i = 0; i < counter; i++) {
		cout << "______________________________" << endl;
		cout << "Contact " << i + 1 << endl;
		ShowOne(contacts[i]);
		cout << "______________________________" << endl;
	}
}
int PhoneBook::SearchbyPIB(PIB pib) {
	for (int i = 0; i < counter; i++) {
		string s = "asd";
		string s2 = "asd";
		if (contacts[i].pib.name == pib.name && contacts[i].pib.surname == pib.surname && contacts[i].pib.fathersname == pib.fathersname) {
			cout << "______________________________" << endl;
			cout << "Contact " << i + 1 << endl;
			ShowOne(contacts[i]);
			cout << "______________________________" << endl;
			return 0;
		}
	}
	cout << "Not found" << endl;
	return -1;
}
void PhoneBook::WriteFile() {
	ofstream Data("data.txt");
	Data << counter << "\n";
	for (int i = 0; i < counter; i++) {
		Data << contacts[i].pib.name << "\n";
		Data << contacts[i].pib.surname << "\n";
		Data << contacts[i].pib.fathersname << "\n";
		Data << contacts[i].phone.home_phone << "\n";
		Data << contacts[i].phone.job_phone << "\n";
		Data << contacts[i].phone.mobile_phone << "\n";
		Data << contacts[i].ADDinfo << "\n";
	}
	Data.close();
}
void PhoneBook::ReadFile() {
	string buffer;
	int countC = 0;
	fstream dat_file("data.txt");
	int curr_line = 1;
	while (getline(dat_file, buffer)) {
		if (curr_line == 1) {
			if (!buffer.empty()) {
				countC = std::stoi(buffer);
			}
		}
		curr_line++;
	}
	dat_file.close();

	fstream dd("data.txt");
	Contact* nConts = new Contact[countC];
	int start_line = 2;
	curr_line = 1;
	for (int i = 0; i < countC; i++) {
		while (getline(dd, buffer)) {
			curr_line++;
			if (curr_line == start_line + 1) {
				nConts[i].pib.name = buffer;
			}
			else if (curr_line == start_line + 2) {
				nConts[i].pib.surname = buffer;
			}
			else if (curr_line == start_line + 3) {
				nConts[i].pib.fathersname = buffer;
			}
			else if (curr_line == start_line + 4) {
				nConts[i].phone.home_phone = buffer;
			}
			else if (curr_line == start_line + 5) {
				nConts[i].phone.job_phone = buffer;
			}
			else if (curr_line == start_line + 6) {
				nConts[i].phone.mobile_phone = buffer;
			}
			else if (curr_line == start_line + 7) {
				nConts[i].ADDinfo = buffer;
				start_line += 7;
				break;
			}
		}
	}
	delete[] contacts;
	counter = countC;
	contacts = nConts;
	dd.close();
}

int mainPhone() {
	PhoneBook phoneBook;
	while (1) {
		int a;
		cout << "Enter action" << endl;
		cout << "1 - add\n2 - delete\n3 - search by PIB\n4 - show all\n5 - download to file\n6 - upload from file\n7 - quit : " << endl;
		cin >> a;
		switch (a) {
		case 1:
		{
			Contact c;
			cout << "PIB: " << endl;
			cin >> c.pib.name >> c.pib.surname >> c.pib.fathersname;
			cout << "Home phone: ";
			cin >> c.phone.home_phone;
			cout << "Job phone: ";
			cin >> c.phone.job_phone;
			cout << "Mobile phone: ";
			cin >> c.phone.mobile_phone;
			cout << "Additional info: ";
			cin >> c.ADDinfo;
			phoneBook.AddNew(c);
		}
			break;
		case 2:
			int d;
			cout << "Enter contact to delete: ";
			cin >> d;
			phoneBook.DeleteOne(d - 1);
			break;
		case 3:
		{
			string n;
			string srnm;
			string fname;
			cout << "Enter PIB to search: " << endl;
			cin >> n >> srnm >> fname;
			phoneBook.SearchbyPIB({ n,srnm,fname });
		}
		break;
		case 4:
			phoneBook.ShowAll();
			break;
		case 5:
			phoneBook.WriteFile();
			break;
		case 6:
			phoneBook.ReadFile();
			break;
		case 7:
			return 0;
		default:
			return 1;
		}
	}
	return 0;
}

int main() {
	mainPhone();
	return 0;
}
