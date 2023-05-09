#include <iostream>
#include <vector>

#define N 10005

using namespace std;

vector<int> e[N];
int deg[N];

int main()
{
    bool ok = false;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    ok = q.size() > 1;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        cnt++;
        cout << u << " ";
    }
    cout << flush;
    return 0;
}