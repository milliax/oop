#include "PrimeFactorization.h"

bool prime_table[BigValue + 10] = {false};
vector<int> prime_numbers = {2};

void PrimeFactorization::Get_Prime_Factorization() {
    // FIND Prime
    const int bigger_number = max(num1, num2);

    if(!prime_table[2]){
		create_prime_table();
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

void PrimeFactorization::create_prime_table(){
	// Create Prime Table
    for (int i = 2; i < BigValue; i++) {
        if (!prime_table[i]) {
            prime_numbers.push_back(i);
            cout << i << " is prime number" << endl;
            for (int j = i * i; i < BigValue; j += i) {
                prime_table[j] = true;
            }
        }
    }
}