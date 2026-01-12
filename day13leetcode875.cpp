#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long calchour(vector<int>& piles, int h)
    {
        long long total=0;
        for(int i=0;i<piles.size();i++)
        {
            total+=((piles[i]+h-1)/h);

        }
    return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long totalhour=calchour(piles, mid);
            if(totalhour<=h)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};