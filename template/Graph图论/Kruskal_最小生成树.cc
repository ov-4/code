#include <iostream>
#include <algorithm>
#define N 1000005

using namespace std;
int n, m;
int a[N];

struct Node
{
    int x, y, z; // x, y是两个点
                 // z 边权
}e[N];

void init()
{
    for (int i = 0; i < n; i++)
        a[i] = i;
}

bool cmp(Node a, Node b)
{
    return a.z < b.z;
}

int find(int x)
{
    if (x == a[x]) return x;
    a[x] = find(a[x]); // 使用父节点找根节点
    return a[x];
}

int solve()
{
    int ans = 0, cnt = 1; // cnt: 边的数量
                          // ans: 边权和
    for (int i = 0; i < m; i++)
    {
        int x = find(e[i].x);
        int y = find(e[i].y);
        if (x != y) // 根节点不同 可以合并
        {
            ans += e[i].z;
            cnt++;
            if (cnt == n)
                return ans;
            a[x] = y;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
        cin >> e[i].x >> e[i].y >> e[i].z;
    sort(e+0, e+m, cmp);
    int res = solve();
    if (res == -1) cout << "orz" << endl;
    else cout << res << endl;
    return 0;
}