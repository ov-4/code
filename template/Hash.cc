#include <iostream>
#include <string>
#include <algorithm>
#define MOD 1073807359ll
#define BASE 257ll
#define N 10005ull

typedef long long ll;
using namespace std;
string s[N]; unsigned long long Hash[N];


unsigned long long get_hash(const string& s)
{
    unsigned long long res = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        res = (ll)(res * BASE + s[i]) % MOD;
    }
    return res;
}

bool isequal(const string &s, const string &t)
{
    return get_hash(s) == get_hash(t);
}

int main()
{
    int n; int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        Hash[i] = get_hash(s[i]);
    }
    sort(Hash, Hash + n);
    for (int i = 0; i < n; i++)
    {
        if (Hash[i] != Hash[i+1])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}