
#include <iostream>
#include "fact.h"
#include "sin.h"
#include "combination.h"
#define M_PI 3.14159265358979323846

using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++) {
        cout << i << "\t" << fact(i) << "\n";
    }
    cout << "\n";
    
    for (double i = 0; i <= M_PI/4; i +=M_PI/180) {
        cout << i << " \t" << sin(i, 5) << "\n";
    }
    cout << "\n";

    for (int i = 1; i <= 10; i++) {
        cout << i << "\t" << comb(10, i) << "\n";
    }
}

