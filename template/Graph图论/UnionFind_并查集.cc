#include <iostream>
#define N 1000005

using namespace std;
int a[N]; // a[i]表示i的根节点
int n, m, op, x, y;

void init()
{
    for (int i = 0; i <= n; i++)
        a[i] = i;
}

int find(int x)
{
    if (x == a[x]) return x;
    a[x] = find(a[x]); // 使用父节点找根节点
    return a[x];
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        cin >> op >> x >> y;
        x = find(x);
        y = find(y);
        if (op == 1)
            a[x] = y;
        else
            cout << (x == y ? "Y" : "N") << endl;
    }
    return 0;
}