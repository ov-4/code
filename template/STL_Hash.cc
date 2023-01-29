#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, int> m;

int main()
{
    int n, cnt = 0; string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        m[s]++;
    }
    for (auto &c : m)
        cnt++;
    cout << cnt << endl;
}