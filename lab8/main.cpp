#include <iostream>
using namespace std;


class Engine {
private:
	int m_EngineCapacity;
	int m_Horsepower;
	bool m_EngineRunning;
public:
	Engine(int EngineCapacity=2000,int Horsepower=200) {
		m_EngineCapacity = EngineCapacity;
		m_Horsepower = Horsepower;
	}
	bool EngineStart() {
		if (!m_EngineRunning) {
			m_EngineRunning = true;
		}
		return true;
	}
	bool EngineStop() {
		if (!m_EngineRunning) {
			m_EngineRunning = false;
		}
		return true;
	}
	bool getEngineStatus() {
		return m_EngineRunning;
	}
};

class Fueltank {
private:
	int m_FueltankCapacity;
	int m_Gas_grade;
public:
	Fueltank(int FueltankCapacity = 3000, int Gas = 98) {
		m_FueltankCapacity = FueltankCapacity;
		m_Gas_grade = Gas;
	}
	int fuel_up(int v, int gas) {
		bool capFlag = false, gasFlag = false;

		if (v > m_FueltankCapacity) {
			cout << "Error: FueltankCapacity:" << m_FueltankCapacity << "but fuel up: " << v << endl;
			capFlag = true;
			return 0;
		}

		if (gas != m_Gas_grade) {
			cout << "Error: Gas_grade:" << gas << "Correct Gas_grade: " << m_Gas_grade << endl;
			gasFlag = true;
			return 0;
		}

		if (v <= m_FueltankCapacity && gas == m_Gas_grade) {
			m_FueltankCapacity = v;
			m_Gas_grade = gas;
			cout << "fuel_up: " << v << " Gas_grade: " << gas;
		}
	}
	int set_Gas_grade(int Gas_grade) {
		m_Gas_grade = Gas_grade;
		cout << "Set Gas_grade: " << Gas_grade << endl;
		return 0;
	}
	int get_Gas_grade() {
		return m_Gas_grade;
	}
};

class Car {
private:
	Engine m_Engine;
	Fueltank m_Fueltank;
	int m_MaxSeating;
	int m_Price;
	int m_base;
	string m_brand;
	string m_model;
	int m_year;
	void m_UpdatePrice(int base = 500000) {
		m_Price = base;
	}
public:
	Car(string x, string y, int z, int s) {
		m_brand = x;
		m_model = y;
		m_year = z;
		m_MaxSeating = s;
	}
	int get_m_MaxSeating() {
		return m_MaxSeating;
	}
	int get_Price() {
		return m_Price;
	}
	void set_base(int n) {
		m_base = n;
	}
	string get_brand() {
		return m_brand;
	}
	bool get_EngineStatus() {
		m_Engine.getEngineStatus();
	}
	bool startEngine() {
		return m_Engine.EngineStart();
	}
	bool stopEngine() {
		return m_Engine.EngineStop();
	}
	int get_Gas_grade() {
		return m_Fueltank.get_Gas_grade();
	}
	int set_Gas_grade(int gas = 98) {
		m_Fueltank.set_Gas_grade(gas);
		return 0;
	}
	int fuel_up(int v, int gas = 98) {
		m_Fueltank.fuel_up(v, gas);
		return 0;
	}
};


class BMW_Car : public Car {
private:
	string m_DriveMode;
public:
	BMW_Car(string y, int z, int s) :Car("BMW", y, z, s) {
		cout << "Constructing BMW_Car\n";
		m_DriveMode = "Rear-wheel";
	}
	string get_DriveMode() {
		return m_DriveMode;
	}
};

class AUDI_Car : public Car {
private:
	string m_DriveMode;
public:
	AUDI_Car(string y, int z, int s) :Car("AUDI", y, z, s) {
		cout << "Constructing AUDI_Car\n";
		m_DriveMode = "Front-wheel";
	}
	string get_DriveMode() {
		return m_DriveMode;
	}
};

class BENZ_Car : public Car {
private:
	string m_DriveMode;
public:
	BENZ_Car(string y, int z, int s) :Car("BENZ", y, z, s) {
		cout << "Constructing BENZ_Car\n";
		m_DriveMode = "Front-wheel";
	}
	string get_DriveMode() {
		return m_DriveMode;
	}
};

int main() {
	AUDI_Car car_2("A3", 2021, 2);
	cout << car_2.get_brand() << ": Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.set_Gas_grade(95);
	cout << car_2.get_brand() << ": Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.fuel_up(300, 95);

	return 0;
}
