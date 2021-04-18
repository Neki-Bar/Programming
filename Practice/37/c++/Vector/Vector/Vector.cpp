#include <iostream>

using namespace std;

const auto e = 1E-10;

double sqr(double a);
bool equal(double a, double b, double e = 1E-10);


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
	Point(double a1, double a2) {
		x = a1;
		y = a2;
	}
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
		return x;
	}
	double get_r() {
		return r; 
	}
	double get_y() {
		return y; 
	}
	double get_phi() {
		return phi;
	}
	void set_x(double a) {
		x = a;
		r = sqrt(pow(a, 2) + pow(y, 2));
		phi = atan2(y, a);
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
	return (abs(a.get_x() - b.get_x()) < exp(-10) && abs(a.get_y() - b.get_y()) < exp(-10));
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


class Vector {
	double x;
	double y;
public:
	Vector() : x(1), y(0) {}
	Vector(Point end) : x(end.get_x()), y(end.get_y()) {}
	Vector(Point begin, Point end) : x(end.get_x() - begin.get_x()), y(end.get_y() - begin.get_y()) {}
	Vector(double x, double y): x(x), y(y) {}

	double get_x() {
		return x;
	}
	double get_y() {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}

	double length() {
		return sqrt(pow(this->get_x(), 2) + pow(this->get_y(), 2));
	}
};

bool operator == (Vector a, Vector b) {
	/*if (a.get_x()/abs(a.get_x()) != b.get_x()/abs(b.get_x()) || a.get_y() / abs(a.get_y()) != b.get_y() / abs(b.get_y())) {
		return  false;
	}
	else {
		return (abs(a.get_x())-abs(b.get_x())) < pow(10, -10) && abs(a.get_y()) - abs(b.get_y()) < pow(10, -10);
	}*/
	return (abs(a.get_x() - b.get_x()) < exp(-10) && abs(a.get_y() - b.get_y()) < exp(-10));
}

Vector operator- (Vector& a) {
	return Vector(-a.get_x(), -a.get_y());
}

Vector operator+ (Vector a, Vector b) {
	Vector c(a.get_x() + b.get_x(), a.get_y()+b.get_y());
	return c;
}

Vector operator- (Vector a, Vector b) {
	Vector c(a.get_x() - b.get_x(), a.get_y() - b.get_y());
	return c;
}

Vector operator* (Vector a, double t) {
	Vector c(a.get_x()*t, a.get_y()*t);
	return c;
}

double operator* (Vector a, Vector b) {
	return a.get_x() * b.get_x() + a.get_y() * b.get_y();
}
int main()
{
	Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
	if (a == b && b == a) cout << "Equality test passed\n";
	else cout << "Equality test failed\n";

	Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
	if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
	else cout << "Invert test failed\n";

	if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
	else cout << "Summation test failed\n";

	if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
	else cout << "Subtraction test failed\n";

	if (ox * 3 == ox + ox + ox &&
		oy * 3 == oy + oy + oy &&
		ox * (-3) == -ox - ox - ox &&
		oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
	else cout << "Multiplication by number test failed\n";

	if (equal(ox.length(), 1) &&
		equal(oy.length(), 1) &&
		equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
	else cout << "Length test failed\n";

	if (equal(ox * ox, sqr(ox.length())) &&
		equal(oy * oy, sqr(oy.length())) &&
		equal((ox * 3 + oy * 4) * (ox * 3 + oy * 4), sqr((ox * 3 + oy * 4).length()))) cout << "Multiplication by Vector test passed\n";
	else cout << "Multiplication by Vector test failed\n";
}

bool equal(double a, double b, double e) {
	if (-e < a - b && a - b < e) return true;
	else return false;
}

double sqr(double a) {
	return a * a;
}

