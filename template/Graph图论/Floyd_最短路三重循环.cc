#include <cmath>
#include <iostream>
#include <vector>
#define MOD 998244354
#define N 505
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
long long n, m, s, f[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            f[i][j] = INF;
        f[i][i] = 0;
    }
    for ( int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], 1ll * w);
    }
    floyd();
    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            sum += f[i][j];
        }
        cout << sum % MOD << endl;
    }
}