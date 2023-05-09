#include <iostream>
#include <set>
#include <algorithm>

// #define DEBUG

using namespace std;

int main()
{
    set<int> a;
    int n, x, op;
    cin >> n;
    a.insert(2147483647); a.insert(-2147483647); // 没有前驱后继就输出这个
    for (int i = 0; i < n; i++)
    {
        cin >> op >> x;
        if (op == 1)
        {
            int pos = 0;
            for (auto b = a.begin(); b != a.end(); pos++, b++)
                if (*b >= x)
                {
                    cout << pos << "\n";
                    break;
                }
            #ifdef DEBUG
            cout << flush;
            #endif
        }
        if (op == 2)
        {
            auto b = a.begin(); b++;
            for (int cnt = 1; b != a.end(); b++, cnt++)
                if (cnt == x)
                    break;
            cout << *b << "\n";
            #ifdef DEBUG
            cout << flush;
            #endif
        }
        if (op == 3)
        {
            auto it = lower_bound(a.begin(), a.end(), x);
            cout << *(--it) << "\n";
            #ifdef DEBUG
            cout << flush;
            #endif
        }
        if (op == 4)
        {
            cout << *upper_bound(a.begin(), a.end(), x) << "\n";
            #ifdef DEBUG
            cout << flush;
            #endif
        }
        if (op == 5)
        {
            a.insert(x);
            #ifdef DEBUG
            for (auto c : a)
                cout << c << " ";
            cout << endl;
            #endif

        }
    }
    cout << flush;
    return 0;
}