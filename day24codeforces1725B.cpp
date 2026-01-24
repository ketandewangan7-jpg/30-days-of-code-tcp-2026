#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long d;
    cin >> n >> d;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int i = 0;
    int j = n - 1;
    int ans = 0;

    while(i <= j)
    {
        long long x = a[j];
        long long need = d / x + 1;

        if(j - i + 1 >= need)
        {
            ans = ans + 1;
            i = i + need - 1;
            j = j - 1;
        }
        else
        {
            break;
        }
    }

    cout << ans;
    return 0;
}
