// Strongest Friendship Group
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int n, m;
vector<int> g[100005];
int cnt[100005];
bool vis[100005];
priority_queue<pair<int, int>> q;
stack<pair<int, int>> ins;
int f[100005];
int h[100005];
int s[100005];
int ms = 1;
int find(int a)
{
    if (f[a] != a)
    {
        f[a] = find(f[a]);
    }
    return f[a];
}
void unite(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    if (ra == rb)
    {
        return;
    }
    if (h[ra] > h[rb])
    {
        f[rb] = ra;
        h[ra] = max(h[ra], h[rb] + 1);
        s[ra] += s[rb];
        ms = max(ms, s[ra]);
    }
    else
    {
        f[ra] = rb;
        h[rb] = max(h[rb], h[ra] + 1);
        s[rb] += s[ra];
        ms = max(ms, s[rb]);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        cnt[a]++;
        g[b].push_back(a);
        cnt[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        q.push({-cnt[i], i});
    }

    int km = 0;
    while (!q.empty())
    {
        auto [k, a] = q.top();
        q.pop();
        if (vis[a])
        {
            continue;
        }
        vis[a] = true;
        k = -k;
        if (k > km)
        {
            ins.push({a, k});
            km = k;
        }
        else
        {
            ins.push({a, -1});
        }

        for (auto b : g[a])
        {
            cnt[b]--;
            q.push({-cnt[b], b});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        s[i] = 1;
        h[i] = 1;
        vis[i] = false;
    }

    long long ans = 1;

    while (!ins.empty())
    {
        auto [a, k] = ins.top();
        vis[a] = true;
        for (auto b : g[a])
        {
            if (vis[b])
            {
                unite(a, b);
            }
        }
        if (k != -1)
        {
            ans = max(ans, (long long)k * ms);
        }
        ins.pop();
    }
    cout << ans << endl;
    return 0;
}