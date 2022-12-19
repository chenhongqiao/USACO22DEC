// Bribing Friends
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b;
struct cow
{
    int p, c, x;
};
int dp[2005][2005];
int main()
{
    cin >> n >> a >> b;
    vector<cow> f(n);
    for (auto &[p, c, x] : f)
    {
        cin >> p >> c >> x;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = a; j >= 0; j--)
        {
            for (int k = b; k >= 0; k--)
            {
                int mx = 0;
                auto [p, c, x] = f[i - 1];
                for (int l = k; l >= 0; l--)
                {
                    if (l / x - c > 0)
                    {
                        continue;
                    }
                    if (j - c + l / x < 0)
                    {
                        break;
                    }
                    mx = max(mx, dp[j - c + l / x][k - l] + p);
                }
                dp[j][k] = max(dp[j][k], mx);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}