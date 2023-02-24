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
        while (i + j + 1 < n)
        {
            if (days[i + j + 1] - days[i + j] < k + 1)
            {
                j++;
            }
            else
            {
                break;
            }
        }
        j--;
        if (j != -1)
        {
            ct += days[i + j + 1] - days[i + j] + k + 1;
            i += abs(0 - j);
        }
        else
        {
            ct += 1 + k;
            if (i == n - 2)
            {
                ct += 1 + k;
            }
        }
    }
    cout << ct;
    system("pause");
    return 0;
}