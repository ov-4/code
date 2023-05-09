#include <iostream>
#include <queue>
#define N 100005
#define LAND '#'

using namespace std;
int n, m, cnt, sz;
string s[N];
bool used[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

namespace dfs
{
    void dfs(int x, int y)
    {
        sz++;
        used[x][y] == true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !used[nx][ny] && s[nx][ny] == LAND)
            {
                dfs(nx, ny);
                cnt++;
            }
        }
    }

    void solve_dfs()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!used[i][j] && s[i][j] == LAND)
                {
                    sz = 0;
                    dfs(i, j);
                }
            }
        }
    }
}

namespace dsu // there're some BUGS
{
    int sum[N];
    int f[N];

    int find(int x)
    {
        return f[x] == x ? x : f[x] = find(f[x]);
    }

    int get_id(int x, int y)
    {
        return x * m + y;
    }

    void merge(int x, int y)
    {
        x = find(x); y = find(y);
        if (x == y) return;
        f[x] = y;
        sum[y] += sum[x];
    }

    void solve_dsu()
    {
        for (int i = 0; i < n * m; i++)
        {   
        f[i] = i;
        sum[i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
               if (s[i][j] == LAND)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] == LAND)
                        {
                            merge(get_id(i, j), get_id(ni, nj));
                        }
                    }
                }
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = get_id(i, j);
                if (s[i][j] == LAND && find(x) == x) // if x is the root
                {
                    cnt++;
                }
            }
        }
    }
}

namespace bfs
{
    void solve_bfs()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!used[i][j] && s[i][j] == LAND)
                {
                    sz = 0;
                    bfs(i, j);
                }
            }
        }
    }

    void bfs(int sx, int sy)
    {
        queue<pair<int, int>> q;
        q.push({sx, sy});
        used[sx][sy] == true;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !used[nx][ny] && s[nx][ny] == LAND)
                {
                    cnt++;
                }
            }
        }
    }

}

void init()
{
    cnt = 0, sz = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            used[i][j] = false;
}

int main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
}