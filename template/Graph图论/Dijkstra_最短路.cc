#include <iostream>
#include <vector>
#define INF INT32_MAX
#define N 10005

using namespace std;

int n, m, s, d[N], e[N][N];
bool used[N];

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mi = INF, u = -1;
        for (int v = 1; v <= n; v++)
        {
            if (!used[v] && d[v] < mi)
            {
                mi = d[v];
                u = v;
            }
        }
        if (u == -1) // can't find
            break;
        used[u] = true;
        for (int v = 1; v <= n; v++)
        {
            if (d[u] != INF && e[u][v] != INF && d[v] > d[u] + e[u][v])
            {
                d[v] = min(d[v], d[u] + e[u][v]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            e[i][j] = INF;
        e[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = min(e[u][v], w);
    }
    dijkstra(s);
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << flush;
    return 0;
}