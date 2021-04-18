#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

const auto PI = 3.141592653589793;

enum SystemType {
	Cartesian,
	Polar
};

class Point {
	double x = 0;
	double y = 0;
	double r = 0;
	double phi = 0;
	SystemType system = Cartesian;
public:
	Point() {}
	Point(double a1, double a2, SystemType coord_system) {
		if (coord_system) {
			r = a1;
			phi = a2;
		}
		else {
			x = a1;
			y = a2;
		}
	}

	double get_x() {
		return x;// system ? a1 * cos(a2) : a1;
	}
	double get_r() {
		return r; // system ? a1 : sqrt(pow(a1, 2) + pow(a2, 2));
	}
	double get_y() {
		return y; // system ? a1 * sin(a2) : a2;
	}
	double get_phi() {
		return phi; // system ? a2 : atan(a2 / a1);
	}
	void set_x(double a) {
	x = a;
	r = sqrt(pow(a, 2) + pow(y, 2));
	phi = atan2(y , a);
	}
	void set_r(double a) {	
		r = a;
		x = r * cos(phi);
		y = r * sin(phi);

	}
	void set_y(double a) {
		y = a;
		r = sqrt(pow(x, 2) + pow(a, 2));
		phi = atan2(a, x);
	}
	void set_phi(double a) {
		phi = a;
		x = r * cos(phi);
		y = r * sin(phi);
	}
};



bool operator== (Point& a, Point& b) {
	if (abs(a.get_x() - b.get_x()) < exp(-10) && abs(a.get_y() - b.get_y()) < exp(-10)) return true;
	else return false;
}

bool operator!= (Point& a, Point& b) {
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, Point& a) {
	os << "(" << a.get_x() << "," << a.get_y() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& a) {
	double x, y;
	is.ignore(1);
	is >> x;
	is.ignore(1);
	is >> y;
	is.ignore(1);
	a.set_x(x);
	a.set_y(y);
	return is;
}



int main(){
	std::vector<Point> original;
	std::ifstream fin("data.txt");
	if (!fin.is_open()) {
		std::cout << "Can't open file" << std::endl;
		return 1;
	}
	else {
		while (!fin.eof()) {
			Point p;
			fin >> p;
			fin.ignore(2); // Точки разделены двумя символами ", "
			original.push_back(p);
		}
		fin.close();
	}

	std::vector<Point> simulacrum(original);
	for (auto& p : simulacrum) {
		std::cout << p<< "     ";
		p.set_x(p.get_x() + 10);
		p.set_phi(p.get_phi() + 180 * PI / 180);
		p.set_y(-p.get_y());
		p.set_x(-p.get_x() - 10);
		std::cout << p << std::endl;
	}

	if (std::equal(original.begin(), original.end(), simulacrum.begin()))
		std::cout << "\nIt works!\n";
	else
		std::cout << "\nIt not works!\n";
}


