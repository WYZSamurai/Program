#include <list>
#include <iostream>
using namespace std;

typedef struct node
{
    int m;
    int n;

    node(int x, int y)
    {
        m = x;
        n = y;
    }
    node();
} lnode;

int main()
{
    list<node> l;
    node a(1,2);
    system("pause");
    return 0;
}