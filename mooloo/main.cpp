// http://usaco.org/index.php?page=viewproblem&cpid=1289
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int n, k, i, j, ct;
    cin >> n >> k;
    int days[n];
    for (i = 0; i < n; i++)
    {
        cin >> days[i];
    }
    ct = 0;
    for (i = 0; i < n - 1; i++)
    {
        j = 0;
        if (abs(days[i + j + 1] - days[i + j]) < k + 1)
        {
            ct += abs(days[i + j + 1] - days[i + j]);
        }
        else
        {
            ct += 1 + k;
        }
    }
    ct += 1 + k;
    cout << ct;
    system("pause");
    return 0;
}