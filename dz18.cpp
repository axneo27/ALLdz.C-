#include <iostream>
using namespace std;

class Engine {
private:
	float power;
public:
	Engine(float power) {
		this->power = power;
	}
	float getPower() {
		return power;
	}
};

class Wheel {
private:
	int radius;
public:
	Wheel(int radius) {
		this->radius = radius;
	}
	Wheel() : radius(0) {};
	int getRadius() {
		return radius;
	}
};

class Car {
private:
	Engine engine;
	Wheel* wheels = {};
public:
	Car(float power, Wheel* wheels) : engine(power) {
		this->wheels = new Wheel[sizeof(wheels) / sizeof(wheels[0])];
		for (int i = 0; i < sizeof(wheels) / sizeof(wheels[0]); i++) {
			this->wheels[i] = wheels[i];
		}
	}

	float getPower() {
		return engine.getPower();
	};

	int getAvgRadius() {
		int wheelsCount = sizeof(wheels) / sizeof(wheels[0]);
		int s = 0;
		for (int i = 0; i < wheelsCount; i++) {
			s += wheels[i].getRadius();
		}
		return s / wheelsCount;
	};

	int Drive(int distance) {
		return distance / (getPower() * getAvgRadius());
	}

	~Car() {
		if (this->wheels != nullptr) {
			delete[] wheels;
		}
	}
};

class Driver {
private:
	Car* car = nullptr;
public:
	Driver(Car* car) {
		this->car = car;
	}

	Driver() : car(nullptr) {};

	int useCar(Car otherCar, int distance) {
		return otherCar.Drive(distance);
	}

	int useCar(int distance) {
		if (car != nullptr) {
			return car->Drive(distance);
		}
		return -1;
	}

	~Driver() {
		delete car;
	}
};

int main() {
	//test 1
	Wheel wheels[] = { Wheel(10), Wheel(10), Wheel(10), Wheel(10) };
	Car *car = new Car(100, wheels);

	Driver driver(car);
	cout << driver.useCar(1000) << endl;

	//test 2
	Wheel wheels2[] = { Wheel(5), Wheel(5), Wheel(5)};
	Car* car2 = new Car(80, wheels2);

	Driver driver2();
	cout << driver.useCar(*car2, 20000) << endl;

}
