#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> d(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> b[i];
    }

    int left = 0, right = 0, delivery = 0, total = 0;
    while (right < n)
    {
        // check if current day is a delivery day
        if (d[right] == left + 1)
        {
            delivery += b[right];
            right++;
        }
        else
        {
            // check if there are haybales left in the barn
            if (delivery > 0)
            {
                delivery--;
                total++;
                left++;
            }
            else
            {
                // move left pointer to next delivery day
                left = d[right] - 1;
                delivery -= b[left];
            }
        }

        // check if we've reached the end of the time period
        if (left >= t)
        {
            break;
        }
    }

    cout << total << endl;

    return 0;
}
