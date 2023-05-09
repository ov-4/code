#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#define INF 0x3f3f3f3f
#define N 10005

using namespace std;
int n, m, s, d[N], cnt[N];
bool used[N];
vector<pair<int, int>> e[N];

bool spfa(int s) // 判断是否是负环
{
    for (int i = 1; i <= n; i++)
        d[i] = INF, cnt[i] = 0, used[i] = false;
    queue<int> q;
    d[s] = 0;
    used[s] = true;
    q.push(s);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        used[u] = false;
        for (auto [v, w] : e[u])
        {
            if (d[v] > d[u] + w)
            {
                cnt[v]++;
                d[v] = d[u] + w;
                if (cnt[v] >= n) // 松弛次数超过n即为负环
                    return true;
                if (!used[v])
                {
                    used[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        e[i].clear();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w >= 0)
        {
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }   else e[u].push_back({v, w});
    }
    bool ok = spfa(1);
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}