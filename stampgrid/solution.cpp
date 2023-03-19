// http://usaco.org/index.php?page=viewproblem2&cpid=1300
#include <iostream>

using namespace std;

#define MAX_INT 2147483647

int main()
{
    int t, i, n, j, m, k;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cin >> n;
        char a[n][n];
        for (j = 0; j < n; j++)
        {
            for (m = 0; m < n; m++)
            {
                cin >> a[j][m];
            }
        }
        cin >> k;
        char b[k][k];
        for (j = 0; j < k; j++)
        {
            for (m = 0; m < k; m++)
            {
                cin >> b[j][m];
            }
        }
        char result[n][n];
        for (j = 0; j < n; j++)
        {
            for (m = 0; m < n; m++)
            {
                result[j][m] = '.';
            }
        }
        for (int rotate = 0; rotate < 4; rotate++)
        {
            for (int top_row = 0; top_row <= n - k; top_row++)
            {
                for (int left_col = 0; left_col <= n - k; left_col++)
                {
                    bool shouldstamp = true;
                    for (int row = 0; row < k; row++)
                    {
                        for (int col = 0; col < k; col++)
                        {
                            if (b[row][col] == '*')
                            {
                                if (a[top_row + row][left_col + col] != '*')
                                {
                                    shouldstamp = false;
                                }
                            }
                        }
                    }
                    if (shouldstamp)
                    {
                        for (int row = 0; row < k; row++)
                        {
                            for (int col = 0; col < k; col++)
                            {
                                if (b[row][col] == '*')
                                {
                                    result[top_row + row][left_col + col] = '*';
                                }
                            }
                        }
                    }
                }
            }
            char c[k][k];
            for (int row = 0; row < k; row++)
            {
                for (int col = 0; col < k; col++)
                {
                    c[row][col] = b[row][col];
                }
            }
            for (int row = 0; row < k; row++)
            {
                for (int col = 0; col < k; col++)
                {
                    b[row][col] = c[k - col - 1][row];
                }
            }
        }
        bool iscorrect = true;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (result[row][col] != a[row][col])
                {
                    iscorrect = false;
                }
            }
        }
        if (iscorrect)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}