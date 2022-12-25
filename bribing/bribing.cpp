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
bool cmp(cow a, cow b)
{
    return a.x > b.x;
}
int main()
{
    cin >> n >> a >> b;
    vector<cow> f(n);
    for (auto &[p, c, x] : f)
    {
        cin >> p >> c >> x;
    }
    sort(f.begin(), f.end(), cmp);
    for (auto [p, c, x] : f)
    {
        for (int j = a; j >= 0 && c - j <= b / x; j--)
        {
            for (int k = b; k >= 0 && c - j <= k / x; k--)
            {
                int l = min(k, c * x);
                dp[j][k] = max(dp[j][k], dp[j - c + l / x][k - l] + p);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}