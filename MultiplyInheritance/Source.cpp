#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
	string name;
	const int MAXSPEED;
	int numPassengers;
public:
	Vehicle(string n,const int MS, int nP) : name(n), MAXSPEED(MS), numPassengers(nP) {};

	void Info()const {
		cout << "\n----------------------------------\n";
		cout << "Name : " << name << endl;
		cout << "Max speed : " << MAXSPEED << endl;
		cout << "Number of passengers : " << numPassengers << endl;
	}
};

class Car : public Vehicle {
	int engineCapacity;
public:
	Car(string name,const int MS, int nP, int eC) :engineCapacity(eC), Vehicle(name, MS, nP) {};

	void GetEngineCapacity()const {
		cout << "Engine capacity : " << engineCapacity << endl;
	}
};

class Bicycle : public Vehicle {
	int numGears;
public:
	Bicycle( string name,const int MS, int nP, int nG) : numGears(nG), Vehicle(name, MS, nP) {};

	void GetNumGears()const {
		cout << "Number of gears : " << numGears << endl;
	}
};

class Boat : public Vehicle {
	string finType;
public:
	Boat(string name, const int MS, int nP, string fT) : finType(fT), Vehicle(name, MS, nP) {};

	void GetFinType()const {
		cout << "Fin type : " << finType << endl;
	}
};

class Airplane : public Vehicle {
	int wingLength;
public:
	Airplane(string name, const int MS, int nP, int wL) : wingLength(wL), Vehicle(name, MS, nP) {};

	void GetWingLength()const {
		cout << "Wing length : " << wingLength << endl;
	}
};

class HybridVehicleCB : public Car, public Boat {
public:
	HybridVehicleCB(string name, const int MS, int nP, int eC, string fT) :
		Car(name, MS, nP, eC), Boat(name, MS, nP, fT) {};

	void Info()const {
		Car::Info();
		GetEngineCapacity();
		GetFinType();
	}
};

class HybridVehicleBA : public Bicycle, public Airplane {
public:
	HybridVehicleBA(string name, const int MS, int nP, int nG, int wL) :
		Bicycle(name, MS, nP, nG), Airplane(name, MS, nP, wL) {};

	void Info()const {
		Bicycle::Info();
		GetNumGears();
		GetWingLength();
	}
};



class Shape {
public:

	virtual double GetArea()const = 0;

	virtual int GetPerimeter()const = 0;

	virtual void Info()const = 0;
};

class Square : public Shape {
	int side;
public:
	Square(int side) : side(side){};

	int GetPerimeter()const override{
		return side * 4;
	}
	
	double GetArea()const override {
		return side * side;
	}

	void Info()const override {
		cout << "\n--------------------------------------------\n";
		cout << "Side : " << side << endl;
		cout << "Perimeter : " << GetPerimeter() << endl;
		cout << "Area : " << GetArea() << endl;
	}
};

class Rectangle : public Shape {
	int side1;
	int side2;
public:
	Rectangle(int side1, int side2) : side1(side1), side2(side2) {};

	int GetPerimeter()const override {
		return side1 * 2 + side2 * 2;
	}

	double GetArea()const override {
		return side1 * side2;
	}

	void Info()const override {
		cout << "\n--------------------------------------------\n";
		cout << "Side1 : " << side1 << endl;
		cout << "Side2 : " << side2 << endl;
		cout << "Perimeter : " << GetPerimeter() << endl;
		cout << "Area : " << GetArea() << endl;
	}
};

class Triangle : public Shape {
	int a;
	int b;
	int c;
public:
	Triangle(int a, int b, int c) : a(a), b(b), c(c) {};

	int GetPerimeter()const override {
		return a + b + c;
	}

	double GetArea()const override {
		float p = GetPerimeter() / 2;
		return sqrt(p*(p - a) * (p - b) * (p - c));
	}

	void Info()const override {
		cout << "\n--------------------------------------------\n";
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
		cout << "c : " << c << endl;
		cout << "Perimeter : " << GetPerimeter() << endl;
		cout << "Area : " << GetArea() << endl;
	}
};

class Circle : public Shape {
	int radius;
public:
	Circle(int radius) : radius(radius){};

	int GetPerimeter()const override {
		return 2 * 3.14 * radius;
	}

	double GetArea()const override {
		return 3.14 * radius * radius;
	}

	void Info()const override {
		cout << "\n--------------------------------------------\n";
		cout << "Radius : " << radius << endl;
		cout << "Perimeter : " << GetPerimeter() << endl;
		cout << "Area : " << GetArea() << endl;
	}
};

double getAreaOfShapes(const vector<Shape*>& arr) {
	double area = 0;
	for (int i = 0; i < arr.size(); i++) {
		area += arr[i]->GetArea();
	}
	return area;
}

double getPerimeterOfShapes(const vector<Shape*>& arr) {
	double perimeter = 0;
	for (int i = 0; i < arr.size(); i++) {
		perimeter += arr[i]->GetPerimeter();
	}
	return perimeter;
}

int GetPosOfMaxAreaShape(const vector<Shape*>& arr) {
	double max = arr[0]->GetArea();
	int iMax = 0;
	for(int i = 1; i < arr.size(); i++){
		if (max < arr[i]->GetArea()) {
			max = arr[i]->GetArea();
			iMax = i;
			continue;
		}
	}
	return iMax;
}

int GetPosOfMaxPerimeterShape(const vector<Shape*>& arr) {
	double max = arr[0]->GetPerimeter();
	int iMax = 0;
	for (int i = 1; i < arr.size(); i++) {
		if (max < arr[i]->GetPerimeter()) {
			max = arr[i]->GetPerimeter();
			iMax = i;
			continue;
		}
	}
	return iMax;
}

void main() {
	Car car("Ford", 120, 4, 99);
	car.Info();
	car.GetEngineCapacity();
	Bicycle bicycle("Titan", 35, 1, 7);
	bicycle.Info();
	bicycle.GetNumGears();
	Boat boat("Capitan", 70, 16, "Shark");
	boat.Info();
	boat.GetFinType();
	Airplane airplane("Boing", 900, 250, 7);
	airplane.Info();
	airplane.GetWingLength();
	HybridVehicleCB hVCB("Fiat", 95, 8, 8, "Baby shark");
	hVCB.Info();
	HybridVehicleBA hVBA("Titanious", 425, 2, 5, 4);
	hVBA.Info();
	cout << "####################### 2 #######################" << endl << endl;
	vector<Shape*> arr;
	arr.push_back(new Square(8));
	arr.push_back(new Rectangle(5, 12));
	arr.push_back(new Triangle(10, 13, 15));
	arr.push_back(new Circle(5));
	for (int i = 0; i < arr.size(); i++) {
		arr[i]->Info();
	}
	cout << "\n\nShape number with max area : " << GetPosOfMaxAreaShape(arr) << endl;
	cout << "Shape number with max perimeter : " << GetPosOfMaxPerimeterShape(arr) << endl;
}