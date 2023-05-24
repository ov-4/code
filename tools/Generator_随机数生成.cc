// Usage: ./Generator <left> <right> <mount>
// 使用方法： ./Generator <范围起始> <范围结束> <数量>
// https://oi-wiki.org/tools/testlib/generator/

#include <iostream>
#include "../lib/testlib.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    registerGen(argc, argv, 1);
    int l = atoi(argv[1]), r = atoi(argv[2]), n = atoi(argv[3]);
    for (int i = 1; i <= n; i++)
        cout << rnd.next(l, r) << " ";
    return 0;
}
