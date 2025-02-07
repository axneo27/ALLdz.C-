#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

int getLength() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (isLetter(str.at(i)) || isDigit(str.at(i))) {
			count++;
		}
	}
	return count;
}

bool isPalindrome() {
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	string withoutSpaces = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			withoutSpaces += str[i];
		}
	}
	int length = withoutSpaces.length();
	for (int i = 0; i < length / 2; i++) {
		if (tolower(withoutSpaces[i]) != tolower(withoutSpaces[length - i - 1])) {
			return false;
		}
	}
	return true;
}

int countWords() {
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	char symbols[] = { '.', ',', '!', '?', ':', ';', '-'};
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (i < str.length() - 1) {
			if (str.at(i) == ' ' && str.at(i + 1) != ' ') {
				count++;
			}
			for (int j = 0; j < sizeof(symbols); j++) {
				if (str.at(i) == symbols[j] && str.at(i + 1) != ' ') {
					count++;
				}
			}
		}
	}
	return count + 1;
}

string reverseStr() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	string reversed = "";
	for (int i = str.length() - 1; i >= 0; i--) {
		reversed += str[i];
	}
	return reversed;
}

int getSymbolCount() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	char symbol;
	cout << "Enter a symbol: ";
	cin >> symbol;
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == symbol) {
			count++;
		}
	}
	return count;
}

void changeWordsInStr() {
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	string word;
	cout << "Enter a word: ";
	getline(cin, word);
	string replacement;
	cout << "Enter a replacement: ";
	getline(cin, replacement);
	
	while (str.find(word) != string::npos) {
		str.replace(str.find(word), word.length(), replacement);
	}

	cout << str << endl;
}

string getDomain() {
	string email;
	cout << "Enter an email: ";
	cin >> email;

	string domain = "";
	bool hasSymbol = false;
	bool hasDot = false;
	for (int i = 0; i < email.length(); i++) {
		if (email.at(i) == '@') {
			domain += email.substr(i + 1);
			hasSymbol = true;
		}
		if (email.at(i) == '.' && hasSymbol) {
			hasDot = true;
		}
	}

	if (!hasSymbol || !hasDot) {
		return "Invalid email";
	}
	else {
		return domain;
	}
}

string deleteSymbol() {
	string str;
	cout << "Enter a string: ";
	cin >> str;
	char symbol;
	cout << "Enter a symbol: ";
	cin >> symbol;
	string result = "";
	bool found = false;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) != symbol) result += str.at(i);
		else if (str.at(i) == symbol && !found) {
			found = true;
			result += str.at(i);
		}
	}
	return result;
}

string changeDateFormat() {
	string date; 
	cout << "Enter a date: ";
	cin >> date;
	string result = "";
	if (stoi(date.substr(0, 2)) < 1 || stoi(date.substr(0, 2)) > 31) {
		return "Invalid date";
	}
	if (stoi(date.substr(3, 2)) < 1 || stoi(date.substr(3, 2)) > 12) {
		return "Invalid date";
	}
	if (stoi(date.substr(6)) < 1) {
		return "Invalid date";
	}
	result += date.substr(6) + "-";
	result += date.substr(3, 2) + "-";
	result += date.substr(0, 2);
	return result;
}

bool anagram() {
	string str1, str2;
	cout << "Enter the first string: ";
	getline(cin, str1);
	cout << "Enter the second string: ";
	getline(cin, str2);

	string s1 = "";
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != ' ') {
			s1 += tolower(str1[i]);
		}
	}

	string s2 = "";
	for (int i = 0; i < str2.length(); i++) {
		if (str2[i] != ' ') {
			s2 += tolower(str2[i]);
		}
	}

	if (s1.length() != s2.length()) {
		return false;
	}
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return s1 == s2;
}

int main() {
	
}
