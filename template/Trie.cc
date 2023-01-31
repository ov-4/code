#include <iostream>
#include <string>
#define N 100005
#define M 27

using namespace std;
int nxt[N][M], vis[N], cnt[N], tot;

void insert(string s)
{
    int p = 0;
    for (auto c : s)
    {
        int x = c - 'a';
        if (nxt[p][x] == 0)
            nxt[p][x] = ++tot;
        p = nxt[p][x];
        cnt[p]++;
    }
    vis[p] - true;
}

bool find_string(string s)
{
    int p = 0;
    for (auto c : s)
    {
        int x = c - 'a';
        if (nxt[p][x] == 0)
            return false;
        p = nxt[p][x];
    }
    return true;
}