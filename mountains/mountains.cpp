// Mountains
#include <iostream>
#include <vector>
using namespace std;
int n, q;
int cnt[2005];
int main()
{
    cin >> n;
    vector<int> h(n);
    for (auto &a : h)
    {
        cin >> a;
    }
    for (int j = 0; j < n; j++)
    {
        int tmp = 0;
        double mins = 2000000000;
        for (int k = j - 1; k >= 0; k--)
        {
            double s = (double)(h[k] - h[j]) / (k - j);
            if (s <= mins)
            {
                mins = s;
                tmp++;
            }
        }
        cnt[j] = tmp;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        h[x - 1] += y;
        int ans = 0;
        for (int j = x - 1; j < n; j++)
        {
            int tmp = 0;
            double mins = 2000000000;
            for (int k = j - 1; k >= 0; k--)
            {
                double s = (double)(h[k] - h[j]) / (k - j);
                if (s <= mins)
                {
                    mins = s;
                    tmp++;
                }
            }
            cnt[j] = tmp;
        }
        for (int j = 0; j < n; j++)
        {
            ans += cnt[j];
        }
        cout << ans << endl;
    }
    return 0;
}