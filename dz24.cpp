#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Car {
private:
    string name;
    int year;
    float V;
    int price;
public:
    Car(string n, int y, float v, int p) : name(n), year(y), V(v), price(p) {}
    string getName() { return name; }
    int getYear() { return year; }
    float getV() { return V; }
    int getPrice() { return price; }

    void Show() {
        cout << name << " " << year << " " << V << " " << price << endl;
    }

    void operator()() {
        Show();
    }
};

class salon {
private:
    vector<Car> cars;
    int count;
public:
    salon() : count(0) {}

    void addCar(Car c) {
        cars.push_back(c);
        count++;
    }

    void deleteCarByName(string name) {
        for (int i = 0; i < count; i++) {
            if (cars[i].getName() == name) {
                cars.erase(cars.begin() + i);
                count--;
                break;
            }
        }
    }

    void sortByYear() {
        sort(cars.begin(), cars.end(), [](Car c1, Car c2) {
            return c1.getYear() < c2.getYear();
        });
    }

    void sortByPrice() {
        sort(cars.begin(), cars.end(), [](Car c1, Car c2) {
            return c1.getPrice() < c2.getPrice();
        });
    }

    void sortByV() {
        sort(cars.begin(), cars.end(), [](Car c1, Car c2) {
            return c1.getV() < c2.getV();
        });
    }

    void searchByName(string name) {
        auto ptr = find_if(cars.begin(), cars.end(), [name](Car c) {
            return c.getName() == name;
        });
        if (ptr != cars.end()) {
            auto obj = *ptr;
            obj();
            cout << "Found at index: " << endl;
            cout << ptr - cars.begin() << endl;

        } else {
            cout << "Not found" << endl;
        }
    }

    void display() {
        for_each(cars.begin(), cars.end(), [](Car c) {
            c();
        });
    }

    void mainLoop() {
        while (1) {
            cout << "Enter action (1-save,2-delete,3-searchByName,4-display,5-exit): ";
            int action;
            cin >> action;
            if (action == 1) {
                string name;
                int year;
                float V;
                int price;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter V: ";
                cin >> V;
                cout << "Enter price: ";
                cin >> price;
                Car c(name, year, V, price);
                addCar(c);
            } else if (action == 2) {
                string name;
                cout << "Enter name: ";
                cin >> name;
                deleteCarByName(name);
            } else if (action == 3) {
                string name;
                cout << "Enter name: ";
                cin >> name;
                searchByName(name);
            } else if (action == 4) {
                display();
            } else if (action == 5) {
                break;
            }
        }
    }
    
};

int main() {
    salon s;
    s.mainLoop();

    return 0;
}
