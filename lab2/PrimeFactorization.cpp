#include "PrimeFactorization.h"

#include <cstring>
#include <iostream>

bool flag = false;
bool prime_table[BigValue + 10] = {true};
vector<int> prime_numbers;

void PrimeFactorization::Get_Prime_Factorization() {
    // FIND Prime
    const int bigger_number = max(num1, num2);

    if (!flag) {
        // cout << "Create prime table" << endl;
        create_prime_table();
        flag = true;
    }

    for (int e : prime_numbers) {
        if (e > num1) {
            break;
        }
        if (num1 % e == 0) {
            num1_factor.emplace_back(e);
        }
    }

    for (int e : prime_numbers) {
        if (e > num2) {
            break;
        }
        if (num2 % e == 0) {
            num2_factor.emplace_back(e);
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
}

void PrimeFactorization::create_prime_table() {
    // init
    memset(prime_table, true, sizeof(prime_table));

    // Create Prime Table
    for (int i = 2; i < BigValue; i++) {
        if (prime_table[i]) {
            prime_numbers.push_back(i);
            // cout << i << " is prime number" << endl;
            for (int j = i * 2; j < BigValue; j += i) {
                prime_table[j] = false;
            }
        }
    }
}