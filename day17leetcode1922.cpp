#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long Power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % 1000000007;

        base = (base * base) % 1000000007;
        exp = exp / 2;
    }
    return result;
}


    int countGoodNumbers(long long n) {
        if (n % 2 == 0)
            return Power(5, n / 2) * Power(4, n / 2)%1000000007;
        else
            return Power(5, (n / 2) + 1) * Power(4, n / 2)%1000000007;
    }
};
