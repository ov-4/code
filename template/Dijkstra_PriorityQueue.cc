#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 100005
#define M 200005
#define INF 0x3f3f3f3f

using namespace std;
int n, m, s, d[N];
vector<pair<int, int>> e[N];

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s] = 0, s});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int u = p.second, uw = p.first;
        if (d[u] < uw)
            continue;
        for (auto p : e[u])
        {
            int v = p.first, w = p.second;
            if (d[v] > d[u] + w)
            pq.push({d[v] = d[u] + w, v});
        }
    }   
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    dijkstra(s);
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << flush;
    return 0;
}