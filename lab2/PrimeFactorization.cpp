#include "PrimeFactorization.h"

// #define BigValue 10000000000

void PrimeFactorization::Get_Prime_Factorization() {
    // FIND Prime
    const int bigger_number = max(num1, num2);
    // const int bigger_number = 100;

    // Make prime table

    for (int i = 2; i < BigValue; i++) {
        if (!prime_table[i]) {
            prime_numbers.push_back(i);

            for (int j = i * i; i < BigValue; j += i) {
                prime_table[j] = true;
            }
        }
    }

    cout << "Total Primes: " << prime_numbers.size() << endl;

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

    cout << "number1 factors: " << endl;
    for (auto e : num1_factor) {
        cout << e << endl;
    }
    cout << "number2 factors: " << endl;
    for (auto e : num2_factor) {
        cout << e << endl;
    }
}

void PrimeFactorization::Print_GCD_Factorization() {
    // TODO: Use num1_factor and num2_factor to find GCD and print the result.
}