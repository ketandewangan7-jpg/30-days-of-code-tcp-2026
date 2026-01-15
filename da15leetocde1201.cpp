#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long gcd(long long x, long long y) {
        while (y != 0) {
            long long temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    long long lcm(long long x, long long y) {
        return (x / gcd(x, y)) * y;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);
        long long left = 1;
        long long right = (long long)min({a, b, c}) * n;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count =mid / a + mid / b + mid / c - mid / ab - mid / ac - mid / bc + mid / abc;
            if (count >= n)
                right = mid;
            else
                left = mid + 1;
        }

        return (int)left;
    }
};