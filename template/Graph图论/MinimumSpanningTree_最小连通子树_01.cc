#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int N = 200000 + 5;

struct Node {
  int u, v, w;
  bool operator<(const Node& T) const { return w < T.w; }
};

int n, m, f[N], cnt, sum;
Node e[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) {
    return false;
  }
  f[x] = y;
  return true;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n;
  cin >> n;
  sort(e, e + m);
  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    if (merge(u, v)) {
      cnt++;
      sum += w;
    }
  }
  cout << sum << endl;
  return 0;
}