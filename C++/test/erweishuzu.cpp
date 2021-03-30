#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    n = 3;
    m = 4;
    int x = 3;
    vector<vector<int>> vec(n, vector<int>(m, x));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }

    system("pause");
    return 0;
}