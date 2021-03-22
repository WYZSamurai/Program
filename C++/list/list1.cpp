#include <vector>
#include <iostream>
using namespace std;

typedef struct node
{
    int m;
    int n;
} node;

int main()
{
    vector<node> v;
    auto it = v.begin();
    node n = {2, 1};
    node m = {3, 3};
    cout << (it.base() == NULL) << endl;
    v.push_back(n);
    v.push_back(m);
    it = v.begin();
    cout << v.size() << endl;
    cout << (it.base() == NULL) << endl;
    system("pause");
    return 0;
}