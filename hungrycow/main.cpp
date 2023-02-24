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
    long long t, i, j;
    int n;
    cin >> n >> t;
    bale bales[n];
    for (i = 0; i < n; i++)
    {
        cin >> bales[i].day >> bales[i].amt;
    }
    j = 0;
    long long dates = 0, inv = 0;
    for (i = 1; i <= t; i++)
    {
        if (i == bales[dates].day)
        {
            inv += bales[dates].amt;
            dates++;
        }
        if (inv > 0)
        {
            inv--;
            j++;
        }
    }
    cout << j;
    system("pause");
    return 0;
}