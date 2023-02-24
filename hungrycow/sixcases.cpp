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
    long long n, i, ct, t;
    cin >> n >> t;
    bale bales[n];
    for (i = 0; i < n; i++)
    {
        cin >> bales[i].day >> bales[i].amt;
    }
    ct = 0;
    for (i = 0; i < n; i++)
    {
        if (ct >= t)
        {
            break;
        }
        if (bales[i].day + bales[i].amt < t)
        {
            ct += bales[i].amt;
        }
        else
        {
            ct += t - bales[i].day + 1;
        }
    }
    cout << ct;
    system("pause");
    return 0;
}