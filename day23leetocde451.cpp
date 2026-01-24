#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // 1 Count frequency of each character
        for (char ch : s) {
            mp[ch]++;
        }

        // 2 Store in vector for sorting
        vector<pair<char, int>> v;
        for (auto it : mp) {
            v.push_back(it);
        }

        // 3️ Sort by frequency (descending)
        sort(v.begin(), v.end(), [](pair<char,int> &a, pair<char,int> &b) {
            return a.second > b.second;
        });

        // 4️ Build the result string
        string ans = "";
        for (auto it : v) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};
