// Mountains
#include <iostream>
#include <vector>
#include <map>
#define lg(a, b) ((long long)a.first * b.second > (long long)a.second * b.first)
#define lge(a, b) ((long long)a.first * b.second >= (long long)a.second * b.first)
using namespace std;
struct mountain
{
    int h;
    map<int, pair<int, int>> mp;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<mountain> m(n);
    for (auto &[h, mp] : m)
    {
        cin >> h;
    }
    int ans = 0;
    pair<int, int> lst;
    for (int i = 0; i < n; i++)
    {
        auto &[h, mp] = m[i];
        for (int j = i - 1; j >= 0; j--)
        {
            auto slp = make_pair(m[j].h - h, i - j);
            if (mp.empty() || lge(slp, lst))
            {
                mp.insert({j, slp});
                lst = slp;
                ans++;
            }
        }
    }
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        auto &[h, mp] = m[x];
        h += y;

        for (int i = x + 1; i < n; i++)
        {
            auto &[kh, kmp] = m[i];
            auto end = kmp.upper_bound(x);
            auto beg = end;
            auto ns = make_pair(h - kh, i - x);
            if (end == kmp.end() || lge(ns, end->second))
            {
                while (beg != kmp.begin() && lg(ns, prev(beg)->second))
                {
                    beg--;
                    ans--;
                }
                kmp.erase(beg, end);
                ans++;
                kmp.insert({x, ns});
            }
        }
        ans -= mp.size();
        mp.clear();
        pair<int, int> lst;
        for (int j = x - 1; j >= 0; j--)
        {
            auto slp = make_pair(m[j].h - h, x - j);
            if (mp.empty() || lge(slp, lst))
            {
                mp.insert({j, slp});
                lst = slp;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}