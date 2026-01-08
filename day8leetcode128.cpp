#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int> mp;
        int count=1;int longest=1;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        auto it=mp.begin();
        auto next_it=it;
        next_it++;
        while(next_it!=mp.end())
        {
            if(it->first ==next_it->first-1) count++;
            else count=1;
            longest=max(count,longest);
            it++;
            next_it++;
        }
        longest=max(count,longest);
    return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int count=1,longest=1;
        int i=0;
        while(i <nums.size()-1)
        {
            if(nums[i]==nums[i+1])
            {
                i++;
                continue;
            }
            if(nums[i]==nums[i+1]-1) count++;
            else count=1;
            i++;
            longest=max(longest,count);
            
        }
    return longest;
    }
};