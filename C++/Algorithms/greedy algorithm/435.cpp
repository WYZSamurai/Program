#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return 0;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });
    int n = intervals.size();
    int m = 0;
    /*for (int i = 0; i < n - 1; i++)
    {
        if (intervals[i][0] == intervals[i + 1][0])
        {
            if (intervals[i][1] <= intervals[i + 1][1])
            {
                m++;
                n--;
                intervals.erase(intervals.begin() + i + 1);
                i--;
            }
        }
        else
        {
            if (intervals[i][1] > intervals[i + 1][0])
            {
                m++;
                if ((intervals[i][1] - intervals[i][0]) > (intervals[i + 1][1] - intervals[i + 1][0]))
                {
                    n--;
                    intervals.erase(intervals.begin() + i);
                    i--;
                }
                else
                {
                    n--;
                    intervals.erase(intervals.begin() + i + 1);
                    i--;
                }
            }
        }
    }*/
    int right = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < right)
        {
            m++;
        }
        else
        {
            right = intervals[i][1];
        }
    }
    return m;
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
    N = v.size();
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Total = " << m << endl;

    system("pause");
    return 0;
}