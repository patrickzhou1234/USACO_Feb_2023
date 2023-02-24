// http://usaco.org/index.php?page=viewproblem&cpid=1287
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

struct bale
{
    long long day, amt;
};

int main()
{
    long long n, t, i, j, ct;
    cin >> n >> t;
    bool days[t] = {false};
    bale bales[n];
    for (i = 0; i < n; i++)
    {
        cin >> bales[i].day >> bales[i].amt;
    }
    for (i = 0; i < n; i++)
    {
        for (j = bales[i].day - 1; j < bales[i].day + bales[i].amt - 1; j++)
        {
            if (!days[j])
            {
                days[j] = true;
            }
            else
            {
                bales[i].amt++;
            }
        }
    }
    ct = 0;
    for (i = 0; i < t; i++)
    {
        if (days[i])
        {
            ct++;
        }
    }
    cout << ct;
    system("pause");
    return 0;
}