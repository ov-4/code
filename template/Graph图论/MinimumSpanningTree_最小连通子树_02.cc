#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define N 5005
#define INF 0x3f3f3f3f

using namespace std;
bool used[N];
int n, m, e[N][N], d[N], cnt, sum;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            e[i][j] = INF;
        e[i][i] = 0;
        d[i] = INF;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u][v] = e[v][u] = min(e[u][v], w);
    }
    d[1] = 0;
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
        if (u == -1)
        {
            cout << "orz" << endl;
            return 0;
        }
        used[u] = true;
        sum += d[u];
        for (int v = 1; v <= n; v++)
        {
            d[v] = min(d[v], e[u][v]);
        }
    }
    cout << sum << endl;
    return 0;
}