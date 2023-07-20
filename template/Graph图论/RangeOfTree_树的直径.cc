#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#define Size 10005

using namespace std;
vector<int> tree[Size];
int n, ans1, ans2, farest, tmp;
bool visited[Size];

void init()
{
    for (int i = 0; i <= Size; i++)
        visited[i] = false;
}

void dfs(int node, int len, int &maxLen, int &farestNode)
{
    if (visited[node])
        if (len > maxLen)
            ans = maxLen, farestNode = node;
    visited[node] = true;
    len++;
    for (auto c : tree[node]) // 遍历node的子树的所有节点
    {
        dfs(c, len, ans);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, -1, ans1, farest);
    dfs(farest, -1, ans2, tmp);
    cout << max(ans1, ans2) << endl;
    return 0;
}