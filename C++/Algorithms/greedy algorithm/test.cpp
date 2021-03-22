#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    cout << m << ' ' << n << endl;
    vector<vector<int>> v(2);
    v[0].push_back(m);
    v[0].push_back(n);
    cout << v[0].size() << endl;

    system("pause");
    return 0;
}