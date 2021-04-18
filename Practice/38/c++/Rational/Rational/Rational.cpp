#include <iostream>
#include <cmath>

bool equal(double a, double b, double e = 1E-10);


int greatest_common_divisor(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 && b == 0) return 1;
    if (b == 0) return a;
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	if (a > b)
		return greatest_common_divisor(a % b, b);
	return greatest_common_divisor(a, b % a);
}

class Rational {
	int a;
	int b;
public:
    Rational() : a(0), b(1) {};
    Rational(int a, int b);

	bool operator == (Rational a);
	Rational operator + (Rational a);
	Rational operator - (Rational a);
	Rational operator * (Rational a);
	Rational operator / (Rational a);

	static int gcd(int c, int d){
		return greatest_common_divisor(c, d);
	}

	int numerator();
	int denomerator();
	bool isNaN();

	operator double() { return a / b; }
	operator bool() { return (a / b != 0); }
};

Rational::Rational(int a, int b) {
    if (b < 0) {
        this->a = -a;
        this->b = -b;
    }
    else {
        this->a = a;
        this->b = b;
    }
}

bool Rational::operator == (Rational numb) {
    if (this->isNaN() || numb.isNaN()) return false;
	return (numb.a * b == a * numb.b);
}

Rational Rational::operator + (Rational summand) {
    if (this->isNaN()) return summand;
    if (summand.isNaN()) return *this;
	Rational summ(a * summand.b + summand.a * b, b * summand.b);
    if (!summ.isNaN()) {
        int g = gcd(summ.a, summ.b);
	    summ.a /= g;
	    summ.b /= g;
    }
	
	return summ;
}

Rational Rational::operator - (Rational deductible) {
    if (this->isNaN()) return deductible;
    if (deductible.isNaN()) return *this;
	Rational diff(a * deductible.b - deductible.a * b, b * deductible.b);
    if (!diff.isNaN()) {
        int g = gcd(diff.a, diff.b);
        diff.a /= g;
        diff.b /= g;
    }
	return diff;
}

Rational Rational::operator * (Rational multiplier) {
	Rational mult(a * multiplier.a, b * multiplier.b);
    if (!mult.isNaN()) {
        int g = gcd(mult.a, mult.b);
	    mult.a /= g;
	    mult.b /= g;
    }
	
	return mult;
}

Rational Rational::operator / (Rational divider) {
	Rational div(a * divider.b, b * divider.a);
    if (!div.isNaN()) {
        int g = gcd(div.a, div.b);
        div.a /= g;
        div.b /= g;
    }
	return div;
}

int Rational::numerator() {
	return a;
}

int Rational::denomerator() {
	return b;
}

bool Rational::isNaN() {
	return (a == 0 && b == 0);
}

int main()
{

    std::cout << Rational::gcd(91, 65) << "\n" <<
        Rational::gcd(10, 3) << "\n" <<
        Rational::gcd(-10, 3) << "\n" <<
        Rational::gcd(10, -3) << "\n" <<
        Rational::gcd(-10, -3) << "\n" <<
        Rational::gcd(30, 10) << "\n" <<
        Rational::gcd(10, 30) << "\n" <<
        Rational::gcd(0, 10) << "\n" <<
        Rational::gcd(10, 0) << "\n";

    std::cout << !Rational(22, 0).isNaN() << "\n" <<
        !Rational(22, 9).isNaN() << "\n" <<
        !Rational(0, 9).isNaN() << "\n" <<
        !Rational(-22, 9).isNaN() << "\n" <<
        !Rational(-22, 0).isNaN() << "\n" <<
        Rational(0, 0).isNaN() << "\n";

    std::cout << (Rational(22, 0) == Rational(22, 0)) << "\n" <<
        (Rational(22, 0) == Rational(9, 0)) << "\n" <<
        !(Rational(22, 0) == Rational(22, 9)) << "\n" <<
        !(Rational(22, 0) == Rational(-22, 9)) << "\n" <<
        !(Rational(22, 0) == Rational(-22, 0)) << "\n" <<
        !(Rational(22, 0) == Rational(0, 9)) << "\n" <<
        !(Rational(22, 0) == Rational(0, 0)) << "\n" <<

        (Rational(22, 9) == Rational(22, 9)) << "\n" <<
        (Rational(22, 9) == Rational(-22, -9)) << "\n" <<
        (Rational(22, 9) == Rational(110, 45)) << "\n" <<
        (Rational(22, 9) == Rational(-110, -45)) << "\n" <<
        !(Rational(22, 9) == Rational(-22, 9)) << "\n" <<
        !(Rational(22, 9) == Rational(22, -9)) << "\n" <<
        !(Rational(22, 9) == Rational(9, 22)) << "\n" <<
        !(Rational(22, 9) == Rational(22, 0)) << "\n" <<
        !(Rational(22, 9) == Rational(-22, 0)) << "\n" <<
        !(Rational(22, 9) == Rational(0, 9)) << "\n" <<
        !(Rational(22, 9) == Rational(0, 0)) << "\n" <<

        (Rational(0, 1) == Rational(0, 1)) << "\n" <<
        (Rational(0, 1) == Rational(0, 9)) << "\n" <<
        (Rational(0, 1) == Rational(0, -9)) << "\n" <<
        !(Rational(0, 1) == Rational(22, 9)) << "\n" <<
        !(Rational(0, 1) == Rational(-22, 9)) << "\n" <<
        !(Rational(0, 1) == Rational(22, 0)) << "\n" <<
        !(Rational(0, 1) == Rational(-22, 0)) << "\n" <<
        !(Rational(0, 1) == Rational(0, 0)) << "\n" <<

        (Rational(-22, 9) == Rational(-22, 9)) << "\n" <<
        (Rational(-22, 9) == Rational(22, -9)) << "\n" <<
        (Rational(-22, 9) == Rational(-110, 45)) << "\n" <<
        (Rational(-22, 9) == Rational(110, -45)) << "\n" <<
        !(Rational(-22, 9) == Rational(-22, -9)) << "\n" <<
        !(Rational(-22, 9) == Rational(22, 9)) << "\n" <<
        !(Rational(-22, 9) == Rational(9, -22)) << "\n" <<
        !(Rational(-22, 9) == Rational(22, 0)) << "\n" <<
        !(Rational(-22, 9) == Rational(-22, 0)) << "\n" <<
        !(Rational(-22, 9) == Rational(0, 9)) << "\n" <<
        !(Rational(-22, 9) == Rational(0, 0)) << "\n" <<

        (Rational(-22, 0) == Rational(-22, 0)) << "\n" <<
        (Rational(-22, 0) == Rational(-9, 0)) << "\n" <<
        !(Rational(-22, 0) == Rational(22, 9)) << "\n" <<
        !(Rational(-22, 0) == Rational(-22, 9)) << "\n" <<
        !(Rational(-22, 0) == Rational(22, 0)) << "\n" <<
        !(Rational(-22, 0) == Rational(0, 9)) << "\n" <<
        !(Rational(-22, 0) == Rational(0, 0)) << "\n" <<

        !(Rational(0, 0) == Rational(0, 0)) << "\n"; 

    std::cout << (Rational(22, 0) + Rational(22, 0) == Rational(22, 0)) << "\n" <<
        (Rational(22, 9) + Rational(22, 0) == Rational(22, 0) )<< "\n" <<
        (Rational(0, 9) + Rational(22, 0) == Rational(22, 0) )<< "\n" <<
        (Rational(-22, 9) + Rational(22, 0) == Rational(22, 0)) << "\n" <<
        (Rational(-22, 0) + Rational(22, 0)).isNaN() << "\n" <<

       ( Rational(22, 0) + Rational(22, 9) == Rational(22, 0) )<< "\n" <<
       ( Rational(22, 9) + Rational(22, 9) == Rational(44, 9) )<< "\n" <<
       ( Rational(0, 9) + Rational(22, 9) == Rational(22, 9) )<< "\n" <<
       ( Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) )<< "\n" <<
        (Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) )<< "\n" <<

       ( Rational(22, 0) + Rational(0, 1) == Rational(22, 0) )<< "\n" <<
       ( Rational(22, 9) + Rational(0, 1) == Rational(22, 9)) << "\n" <<
       ( Rational(0, 9) + Rational(0, 1) == Rational(0, 9) )<< "\n" <<
       ( Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9)) << "\n" <<
       ( Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) )<< "\n" <<

       ( Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) )<< "\n" <<
       ( Rational(22, 9) + Rational(-22, 9) == Rational(0, 9)) << "\n" <<
       ( Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9)) << "\n" <<
       ( Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9)) << "\n" <<
       ( Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) )<< "\n" <<

        (Rational(22, 0) + Rational(-22, 0)).isNaN() << "\n" <<
       ( Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) )<< "\n" <<
       ( Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) )<< "\n" <<
       ( Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0)) << "\n" <<
       ( Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) )<< "\n" <<

        (Rational(22, 0) + Rational(0, 0)).isNaN() << "\n" <<
        (Rational(22, 9) + Rational(0, 0)).isNaN() << "\n" <<
        (Rational(0, 9) + Rational(0, 0)).isNaN() << "\n" <<
        (Rational(-22, 9) + Rational(0, 0)).isNaN() << "\n" <<
        (Rational(-22, 0) + Rational(0, 0)).isNaN() << "\n";

    std::cout <<(Rational(22, 0) - Rational(22, 0)).isNaN()  << "\n" <<
       ( Rational(22, 9) - Rational(22, 0) == Rational(-22, 0)) << "\n" <<
       ( Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) ) << "\n" <<
       ( Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) ) << "\n" <<
       ( Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) ) << "\n" <<

       ( Rational(22, 0) - Rational(22, 9) == Rational(22, 0) ) << "\n" <<
       ( Rational(22, 9) - Rational(22, 9) == Rational(0, 9) ) << "\n" <<
       ( Rational(0, 9) - Rational(22, 9) == Rational(-22, 9)) << "\n" <<
       ( Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) ) << "\n" <<
       ( Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) ) << "\n" <<

       ( Rational(22, 0) - Rational(0, 1) == Rational(22, 0) ) << "\n" <<
       ( Rational(22, 9) - Rational(0, 1) == Rational(22, 9) ) << "\n" <<
       ( Rational(0, 9) - Rational(0, 1) == Rational(0, 9) ) << "\n" <<
       ( Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) ) << "\n" <<
       ( Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) ) << "\n" <<

       ( Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) ) << "\n" <<
       ( Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) ) << "\n" <<
       ( Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) ) << "\n" <<
       ( Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) ) << "\n" <<
       ( Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) ) << "\n" <<

        (Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) ) << "\n" <<
        (Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) ) << "\n" <<
        (Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) ) << "\n" <<
        (Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) ) << "\n" <<
        (Rational(-22, 0) - Rational(-22, 0)).isNaN()  << "\n" <<

        (Rational(22, 0) - Rational(0, 0)).isNaN()  << "\n" <<
        (Rational(22, 9) - Rational(0, 0)).isNaN()  << "\n" <<
        (Rational(0, 9) - Rational(0, 0)).isNaN()  << "\n" <<
        (Rational(-22, 9) - Rational(0, 0)).isNaN()  << "\n" <<
        (Rational(-22, 0) - Rational(0, 0)).isNaN() << "\n";


    if (Rational::gcd(91, 65) == 13 &&
        Rational::gcd(10, 3) == 1 &&
        Rational::gcd(-10, 3) == 1 &&
        Rational::gcd(10, -3) == 1 &&
        Rational::gcd(-10, -3) == 1 &&
        Rational::gcd(30, 10) == 10 &&
        Rational::gcd(10, 30) == 10 &&
        Rational::gcd(0, 10) == 10 &&
        Rational::gcd(10, 0) == 10) std::cout << "gcd test passed\n";
    else std::cout << "gcd test failed\n";

    if (!Rational(22, 0).isNaN() &&
        !Rational(22, 9).isNaN() &&
        !Rational(0, 9).isNaN() &&
        !Rational(-22, 9).isNaN() &&
        !Rational(-22, 0).isNaN() &&
        Rational(0, 0).isNaN()
        ) std::cout << "isNaN test passed\n";
    else std::cout << "isNaN test failed\n";

    if (Rational(22, 0) == Rational(22, 0) &&
        Rational(22, 0) == Rational(9, 0) &&
        !(Rational(22, 0) == Rational(22, 9)) &&
        !(Rational(22, 0) == Rational(-22, 9)) &&
        !(Rational(22, 0) == Rational(-22, 0)) &&
        !(Rational(22, 0) == Rational(0, 9)) &&
        !(Rational(22, 0) == Rational(0, 0)) &&

        Rational(22, 9) == Rational(22, 9) &&
        Rational(22, 9) == Rational(-22, -9) &&
        Rational(22, 9) == Rational(110, 45) &&
        Rational(22, 9) == Rational(-110, -45) &&
        !(Rational(22, 9) == Rational(-22, 9)) &&
        !(Rational(22, 9) == Rational(22, -9)) &&
        !(Rational(22, 9) == Rational(9, 22)) &&
        !(Rational(22, 9) == Rational(22, 0)) &&
        !(Rational(22, 9) == Rational(-22, 0)) &&
        !(Rational(22, 9) == Rational(0, 9)) &&
        !(Rational(22, 9) == Rational(0, 0)) &&

        Rational(0, 1) == Rational(0, 1) &&
        Rational(0, 1) == Rational(0, 9) &&
        Rational(0, 1) == Rational(0, -9) &&
        !(Rational(0, 1) == Rational(22, 9)) &&
        !(Rational(0, 1) == Rational(-22, 9)) &&
        !(Rational(0, 1) == Rational(22, 0)) &&
        !(Rational(0, 1) == Rational(-22, 0)) &&
        !(Rational(0, 1) == Rational(0, 0)) &&

        Rational(-22, 9) == Rational(-22, 9) &&
        Rational(-22, 9) == Rational(22, -9) &&
        Rational(-22, 9) == Rational(-110, 45) &&
        Rational(-22, 9) == Rational(110, -45) &&
        !(Rational(-22, 9) == Rational(-22, -9)) &&
        !(Rational(-22, 9) == Rational(22, 9)) &&
        !(Rational(-22, 9) == Rational(9, -22)) &&
        !(Rational(-22, 9) == Rational(22, 0)) &&
        !(Rational(-22, 9) == Rational(-22, 0)) &&
        !(Rational(-22, 9) == Rational(0, 9)) &&
        !(Rational(-22, 9) == Rational(0, 0)) &&

        Rational(-22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) == Rational(-9, 0) &&
        !(Rational(-22, 0) == Rational(22, 9)) &&
        !(Rational(-22, 0) == Rational(-22, 9)) &&
        !(Rational(-22, 0) == Rational(22, 0)) &&
        !(Rational(-22, 0) == Rational(0, 9)) &&
        !(Rational(-22, 0) == Rational(0, 0)) &&

        !(Rational(0, 0) == Rational(0, 0))
        ) std::cout << "Equality test passed\n";
    else std::cout << "Equality test failed\n";

    if (Rational(22, 0) + Rational(22, 0) == Rational(22, 0) &&
        Rational(22, 9) + Rational(22, 0) == Rational(22, 0) &&
        Rational(0, 9) + Rational(22, 0) == Rational(22, 0) &&
        Rational(-22, 9) + Rational(22, 0) == Rational(22, 0) &&
        (Rational(-22, 0) + Rational(22, 0)).isNaN() &&

        Rational(22, 0) + Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) + Rational(22, 9) == Rational(44, 9) &&
        Rational(0, 9) + Rational(22, 9) == Rational(22, 9) &&
        Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) &&
        Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) &&

        Rational(22, 0) + Rational(0, 1) == Rational(22, 0) &&
        Rational(22, 9) + Rational(0, 1) == Rational(22, 9) &&
        Rational(0, 9) + Rational(0, 1) == Rational(0, 9) &&
        Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9) &&
        Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) &&

        Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) &&
        Rational(22, 9) + Rational(-22, 9) == Rational(0, 9) &&
        Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9) &&
        Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9) &&
        Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) &&

        (Rational(22, 0) + Rational(-22, 0)).isNaN() &&
        Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
        Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) &&
        Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) &&

        (Rational(22, 0) + Rational(0, 0)).isNaN() &&
        (Rational(22, 9) + Rational(0, 0)).isNaN() &&
        (Rational(0, 9) + Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) + Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) + Rational(0, 0)).isNaN()
        ) std::cout << "Summation test passed\n";
    else std::cout << "Summation test failed\n";

    if ((Rational(22, 0) - Rational(22, 0)).isNaN() &&
        Rational(22, 9) - Rational(22, 0) == Rational(-22, 0) &&
        Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) &&
        Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) - Rational(22, 9) == Rational(0, 9) &&
        Rational(0, 9) - Rational(22, 9) == Rational(-22, 9) &&
        Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) &&
        Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(0, 1) == Rational(22, 0) &&
        Rational(22, 9) - Rational(0, 1) == Rational(22, 9) &&
        Rational(0, 9) - Rational(0, 1) == Rational(0, 9) &&
        Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) &&
        Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) &&
        Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) &&
        Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) &&
        Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) &&
        Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) &&
        Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) &&
        Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) &&
        Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) &&
        (Rational(-22, 0) - Rational(-22, 0)).isNaN() &&

        (Rational(22, 0) - Rational(0, 0)).isNaN() &&
        (Rational(22, 9) - Rational(0, 0)).isNaN() &&
        (Rational(0, 9) - Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) - Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) - Rational(0, 0)).isNaN()
        ) std::cout << "Subtraction test passed\n";
    else std::cout << "Subtraction test failed\n";

    if (Rational(22, 0) * Rational(22, 0) == Rational(22, 0) &&
        Rational(22, 9) * Rational(22, 0) == Rational(22, 0) &&
        (Rational(0, 9) * Rational(22, 0)).isNaN() &&
        Rational(-22, 9) * Rational(22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) * Rational(22, 0) == Rational(-22, 0) &&

        Rational(22, 0) * Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) * Rational(22, 9) == Rational(22 * 22, 9 * 9) &&
        Rational(0, 9) * Rational(22, 9) == Rational(0, 9) &&
        Rational(-22, 9) * Rational(22, 9) == Rational(-22 * 22, 9 * 9) &&
        Rational(-22, 0) * Rational(22, 9) == Rational(-22, 0) &&

        (Rational(22, 0) * Rational(0, 1)).isNaN() &&
        Rational(22, 9) * Rational(0, 1) == Rational(0, 9) &&
        Rational(0, 9) * Rational(0, 1) == Rational(0, 9) &&
        Rational(-22, 9) * Rational(0, 1) == Rational(0, 9) &&
        (Rational(-22, 0) * Rational(0, 1)).isNaN() &&

        Rational(22, 0) * Rational(-22, 9) == Rational(-22, 0) &&
        Rational(22, 9) * Rational(-22, 9) == Rational(-22 * 22, 9 * 9) &&
        Rational(0, 9) * Rational(-22, 9) == Rational(0, 9) &&
        Rational(-22, 9) * Rational(-22, 9) == Rational(22 * 22, 9 * 9) &&
        Rational(-22, 0) * Rational(-22, 9) == Rational(22, 0) &&

        Rational(22, 0) * Rational(-22, 0) == Rational(-22, 0) &&
        Rational(22, 9) * Rational(-22, 0) == Rational(-22, 0) &&
        (Rational(0, 9) * Rational(-22, 0)).isNaN() &&
        Rational(-22, 9) * Rational(-22, 0) == Rational(22, 0) &&
        Rational(-22, 0) * Rational(-22, 0) == Rational(22, 0) &&

        (Rational(22, 0) * Rational(0, 0)).isNaN() &&
        (Rational(22, 9) * Rational(0, 0)).isNaN() &&
        (Rational(0, 9) * Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) * Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) * Rational(0, 0)).isNaN()
        ) std::cout << "Multiplication test passed\n";
    else std::cout << "Multiplication test failed\n";

    if ((Rational(22, 0) / Rational(22, 0)).isNaN() &&
        Rational(22, 9) / Rational(22, 0) == Rational(0, 9) &&
        Rational(0, 9) / Rational(22, 0) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(22, 0) == Rational(0, 9) &&
        (Rational(-22, 0) / Rational(22, 0)).isNaN() &&

        Rational(22, 0) / Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) / Rational(22, 9) == Rational(9, 9) &&
        Rational(0, 9) / Rational(22, 9) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(22, 9) == Rational(-9, 9) &&
        Rational(-22, 0) / Rational(22, 9) == Rational(-22, 0) &&

        Rational(22, 0) / Rational(0, 1) == Rational(22, 0) &&
        Rational(22, 9) / Rational(0, 1) == Rational(22, 0) &&
        (Rational(0, 9) / Rational(0, 1)).isNaN() &&
        Rational(-22, 9) / Rational(0, 1) == Rational(-22, 0) &&
        Rational(-22, 0) / Rational(0, 1) == Rational(-22, 0) &&

        Rational(22, 0) / Rational(-22, 9) == Rational(-22, 0) &&
        Rational(22, 9) / Rational(-22, 9) == Rational(-9, 9) &&
        Rational(0, 9) / Rational(-22, 9) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(-22, 9) == Rational(9, 9) &&
        Rational(-22, 0) / Rational(-22, 9) == Rational(22, 0) &&

        (Rational(22, 0) / Rational(-22, 0)).isNaN() &&
        Rational(22, 9) / Rational(-22, 0) == Rational(0, 9) &&
        Rational(0, 9) / Rational(-22, 0) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(-22, 0) == Rational(0, 9) &&
        (Rational(-22, 0) / Rational(-22, 0)).isNaN() &&

        (Rational(22, 0) / Rational(0, 0)).isNaN() &&
        (Rational(22, 9) / Rational(0, 0)).isNaN() &&
        (Rational(0, 9) / Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) / Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) / Rational(0, 0)).isNaN()
        ) std::cout << "Division test passed\n";
    else std::cout << "Division test failed\n";

    if (equal(Rational(-22, -9), 22 / 9.0) &&
        equal(Rational(-9, -9), 1) &&
        equal(Rational(-6, -9), 6 / 9.0) &&
        equal(Rational(0, -9), 0) &&
        equal(Rational(6, -9), -6 / 9.0) &&
        equal(Rational(9, -9), -1) &&
        equal(Rational(22, -9), -22 / 9.0) &&
        std::isinf((double)Rational(-9, 0)) &&
        std::isnan((double)Rational(0, 0)) &&
        std::isinf((double)Rational(9, 0)) &&
        equal(Rational(-22, 9), -22 / 9.0) &&
        equal(Rational(-9, 9), -1) &&
        equal(Rational(-6, 9), -6 / 9.0) &&
        equal(Rational(0, 9), 0) &&
        equal(Rational(6, 9), 6 / 9.0) &&
        equal(Rational(9, 9), 1) &&
        equal(Rational(22, 9), 22 / 9.0)) std::cout << "Conversion to double test passed\n";
    else std::cout << "Conversion to double test failed\n";

    if (Rational(-22, -9) &&
        Rational(-9, -9) &&
        Rational(-6, -9) &&
        !Rational(0, -9) &&
        Rational(6, -9) &&
        Rational(9, -9) &&
        Rational(22, -9) &&
        Rational(-9, 0) &&
        Rational(0, 0) &&
        Rational(9, 0) &&
        Rational(-22, 9) &&
        Rational(-9, 9) &&
        Rational(-6, 9) &&
        !Rational(0, 9) &&
        Rational(6, 9) &&
        Rational(9, 9) &&
        Rational(22, 9)) std::cout << "Conversion to bool test passed\n";
    else std::cout << "Conversion to bool test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}


