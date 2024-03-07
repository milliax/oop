#ifndef __PrimeFactorization_H__
#define __PrimeFactorization_H__

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// extern bool prime_table[2147483650];
extern vector<bool> prime_table;
extern vector<int> prime_numbers;

class PrimeFactorization {
   private:
    int num1, num2;
    vector<int> num1_factor, num2_factor;
    map<int, int> num1_pow, num2_pow;

   public:
    PrimeFactorization(int num1, int num2) : num1(num1), num2(num2) {}

    void Get_Prime_Factorization();
    void Print_Prime_Factorization();
    void Print_GCD_Factorization();
};

#endif  // __PrimeFactorization_H__
