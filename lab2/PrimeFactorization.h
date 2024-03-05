#ifndef __PrimeFactorization_H__
#define __PrimeFactorization_H__

#include <iostream>
#include <vector>
#define BigValue 1000000000

using namespace std;

class PrimeFactorization {
   private:
    int num1, num2;
    std::vector<int> num1_factor, num2_factor;
    bool prime_table[BigValue] = {};
    vector<int> prime_numbers = {2};

   public:
    PrimeFactorization(int num1, int num2) : num1(num1), num2(num2) {}

    void Get_Prime_Factorization();
    void Print_Prime_Factorization();
    void Print_GCD_Factorization();
};

#endif  // __PrimeFactorization_H__
