#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(vector<vector<int>> &points)
{
    int n = points.size();
    if (n == 0)
        return 0;
    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });
    int num = 0;
    int rear = points[0][1];
    for (int i = 1; i < n; i++)
    {
        if (rear < points[i][0])
        {
            num++;
            rear = points[i][1];
        }
    }
    return num + 1;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i].push_back(a);
        v[i].push_back(b);
    }
    int m = func(v);
    cout << "Total = " << m << endl;

    system("pause");
    return 0;
}