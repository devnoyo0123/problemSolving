#include <iostream>

using namespace std;
const int MAX = 1001;
int val[MAX];
int d[MAX];
int n;
int ans;

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (val[i] > val[j])
            {
                if (d[j] + 1 > d[i])
                {
                    d[i] = d[j] + 1;
                }
            }
        }
        if (ans < d[i])
        {
            ans = d[i];
        }
    }

    cout << ans << '\n';
    return 0;
}