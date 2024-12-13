#include <iostream>
using namespace std;

//QUEUE
//1
class BusStop {
public:
	int avgTimePasOcc;
	int avgTimeBusOcc;
	int StopType; // 1 - end, 0 - no
	int freePlaces;
public:
	BusStop() = delete;
	BusStop(const BusStop& other) = delete; 
	BusStop(int avgTimePassengerOccurence, int avgTimeBusOccurence, int StopType, int time) : avgTimeBusOcc(avgTimeBusOccurence), avgTimePasOcc(avgTimePassengerOccurence), StopType(StopType){
		freePlaces = rand() % 30;
		if (StopType == 1) {
			avgTimeBusOcc *= 0.8;
		}
	}

	float avgTimeOnStop()const {
		int avgPasOnStop = round(avgTimeBusOcc/avgTimePasOcc);

		int sumTime = 0;
		for (int i = 0; i < avgPasOnStop; i++) {
			sumTime += (avgTimeBusOcc - i * avgPasOnStop);
		}
		return (float)sumTime / avgPasOnStop;
	}

	int MinTimeIntervalBuses(int maxPeople)const {
		int adjustedMaxPeople = maxPeople;
		if (freePlaces < maxPeople) adjustedMaxPeople = freePlaces;
		return adjustedMaxPeople * avgTimePasOcc;
	}
};
//2
class Printer {
private:
	int* arr;
	int size;
	int topIndex;

	int timeForOnePrint = 2;
	int* statistics;
	int statSize = 0;
public:
	Printer() = delete;
	Printer(const Printer& other) = delete;
	Printer(int s) : size(s), topIndex(-1) {
		this->arr = new int[size];
	}
	~Printer() {
		if (arr != nullptr) {
			delete[] arr;
			arr = nullptr;
		}
	}

	void addPrint(int client) { // priority
		if (isFull()) {
			size *= 2;
			int* temp = new int[size];
			for (int i = 0; i < size / 2; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
		arr[++topIndex] = client;
		for (int i = topIndex; i > 0; i--) {
			if (arr[i] > arr[i - 1]) {
				arr[i] = arr[i - 1];
				arr[i - 1] = client;
			}
		}

	}

	int PrintOne() {
		if (!isEmpty()) {
			int temp = arr[0];
			for (int i = 0; i < topIndex; i++) {
				arr[i] = arr[i + 1];
			}
			topIndex--;
			int* temp2 = new int[statSize + 1];
			for (int i = 0; i < statSize; i++) {
				temp2[i] = statistics[i];
			}
			temp2[statSize] = temp;
			delete[] statistics;
			statistics = temp2;

			++statSize;
			return temp;
		} 
		return -1;
	}

	void PrintAll() {
		while (!isEmpty()) PrintOne();
	}
	
	void ShowStatistics() {
		for (int i = 0; i < statSize; i++) {
			cout << "User: " << statistics[i] << " Time: " << timeForOnePrint * i << endl;
		}
		cout << "_______________________" << endl;
	}

	bool isFull() {
		return topIndex == size - 1;
	}

	bool isEmpty() {
		return topIndex == -1;
	}
};
//STACK

class CheckEquation {
private:
	char *stack;
	int topIndex = -1;
	int size = 0;

	char left[3] = { '(', '[', '{' };	
	char right[3] = { ')', ']', '}' };

	string eq;

public:
	CheckEquation() = delete;
	CheckEquation(string str) : eq(str){}

	bool HasMistake() {
		if (eq.back() != ';') {
			ShowMistake(eq.size() - 1);
			return false;
		}
		for (int x = 0; x < eq.size(); x++) {
			for (int i = 0; i < 3; i++) {
				if (eq[x] == left[i]) {
					++topIndex;

					char* temp = new char[size + 1];
					for (int j = 0; j < size; j++) {
						temp[j] = stack[j];
					}
					temp[size] = eq[x];
					delete[] stack;
					stack = temp;
					++size;

				}
				else if (eq[x] == right[i]) {
					if (checkIfClosed(eq[x])) {
						--topIndex;

						char *temp = new char[size - 1];
						int k = 0, j;
						for (j = 0; j < size; j++) {
							if (stack[j] == left[i]) {
								continue;
							}
							temp[k] = stack[j];
							++k;
						}
						--size;
						delete[] stack;
						stack = temp;

					}
					else {
						ShowMistake(x);
						return true;
					}
				}
			}
		}
		if (size != 0) {
			ShowMistake(eq.size() - 1); 
			return false;
		}

		return true;
	}

	void ShowMistake(int index) {
		cout << "Mistake: \n";
		for (int i = 0; i < eq.size(); i++) {
			if (i == index) {
				cout << "?" << eq[index] << "?";
			}
			else {
				cout << eq[i];
			}
		}
		cout << endl;
	}

	bool checkIfClosed(char r) {
		if (r == stack[topIndex]) return true;
		return false;
	}

};

int main() {

}
