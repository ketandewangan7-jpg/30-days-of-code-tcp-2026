#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int k=n-1;
        int j=0;
       
        while(i<=k)
        {
            if(arr[i]==0) 
            {
                swap(arr[i],arr[j]);
                j++;
                i++;
            }
            else if(arr[i]==2) 
            {
                swap(arr[k],arr[i]);
                k--;
            }
            else i++;
        }
    }
};