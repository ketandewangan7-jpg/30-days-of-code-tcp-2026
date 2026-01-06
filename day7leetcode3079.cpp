#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // encrypt made to store largest digit in n
    int encrypt(int n) {
        int mx = 0;
        int ans = 0;
        int newn = n;

        // to find maximum digit
        while (newn > 0) { 
            int num = newn % 10; 
            mx = max(num, mx);
            newn = newn / 10;  
        }

        // calculate largest number
        while (n > 0) {
            ans = ans * 10 + mx;
            n /= 10;
        }
        return ans;
    }  

    // sum of vector through above function
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += encrypt(nums[i]);
        }
        return sum;
    }
};
