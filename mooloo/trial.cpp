#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    int ans = 0;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j + 1 < n && d[j + 1] - d[j] <= k)
        {
            j++;
        }

        ans += k + d[j] - d[i] + 1;
        i = j + 1;
    }

    cout << ans << endl;

    return 0;
}