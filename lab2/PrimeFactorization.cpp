#include "PrimeFactorization.h"

#include <cstring>
#include <iostream>

void PrimeFactorization::Get_Prime_Factorization() {
    // const int bigger_number = max(num1, num2);

    int number1 = num1;

    for (int i = 2; i <= num1; ++i) {
        if (number1 == 1) {
            break;
        }

        if (number1 % i == 0) {
            num1_factor.emplace_back(i);
            do {
                number1 /= i;
            } while (number1 % i == 0);
        }
    }

    int number2 = num2;
    for (int i = 2; i <= num2; ++i) {
        if (number2 == 1) {
            break;
        }

        if (number2 % i == 0) {
            num2_factor.emplace_back(i);
            do {
                number2 /= i;
            } while (number2 % i == 0);
        }
    }
}

void PrimeFactorization::Print_Prime_Factorization() {
    // TODO: Print num1_factor and num2_factor.

    int numberA = num1;
    int numberB = num2;

    /* Print number1's factors */

    bool vis = false;
    cout << "num1_prime_factor: ";

    for (auto e : num1_factor) {
        int i = 0;
        while (numberA % e == 0) {
            ++i;
            numberA /= e;
        }

        if (vis) {
            cout << " * ";
        } else {
            vis = true;
        }

        if (i == 1) {
            cout << e;

        } else {
            printf("%d^%d", e, i);
        }
        num1_pow[e] = i;
    }
    cout << endl;

    /* Print number2's factors */

    cout << "num2_prime_factor: ";
    vis = false;

    for (auto e : num2_factor) {
        int i = 0;
        while (numberB % e == 0) {
            ++i;
            numberB /= e;
        }

        if (vis) {
            cout << " * ";
        } else {
            vis = true;
        }

        if (i == 1) {
            cout << e;
        } else {
            printf("%d^%d", e, i);
        }
        num2_pow[e] = i;
    }
    cout << endl;
}

void PrimeFactorization::Print_GCD_Factorization() {
    // TODO: Use num1_factor and num2_factor to find GCD and print the result.

    bool vis = false;

    cout << "GCD_prime_factor: ";

    for (auto p : num1_pow) {
        if (num2_pow.count(p.first)) {
            if (vis) {
                cout << " * ";
            }

            if (min(p.second, num2_pow[p.first]) == 1) {
                cout << p.first;
            } else {
                printf("%d^%d", p.first, min(p.second, num2_pow[p.first]));
                // cout << p.first << min(p.second, num2_pow[p.first]) << endl;
            }

            vis = true;
        }
    }

    if (!vis) {
        cout << 1 << endl;
    }
}