#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void print_factorization(unsigned int x) {
    cout << "Множители: ";
    int divisor = 2;
    map <int, int> divisors;
    map <int, int>::iterator it;
    while (x != 1) {
        if (x % divisor == 0) {
            divisors[divisor]++;
            x /= divisor;
        }
        else {
            divisor += 1;
        }
    }
    for (it = divisors.begin(); it != divisors.end(); it++) {
        if (it->second > 1) {
            if (it != divisors.begin()) cout << "*";
            cout << it->first << "^" << it->second;
        }
        else {
            if (it != divisors.begin()) cout << "*";
            cout << it->first;
        }

    }
}

int main(){
    setlocale(LC_ALL, "rus");
    int x;
    cout << "Введите число для факторизации.\n";
    cin >> x;
    print_factorization(x);
}

