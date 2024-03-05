#include <iostream>

#include "PrimeFactorization.h"

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << "num1 = " << a << endl;
        cout << "num2 = " << b << endl;

        PrimeFactorization PF(a, b);

        PF.Get_Prime_Factorization();
        PF.Print_Prime_Factorization();
        PF.Print_GCD_Factorization();

        cout << endl;
        return 0;
    }

    return 0;
}