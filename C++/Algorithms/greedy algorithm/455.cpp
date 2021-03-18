#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0;
        while (child < g.size() && cookie < s.size())
        {
            if (g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main()
{
    Solution a;
    vector<int> g;
    vector<int> s;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        g.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int y;
        scanf("%d", &y);
        s.push_back(y);
    }
    //printf("%d %d\n", g.size(), s.size());
    printf("%d\n", a.findContentChildren(g, s));

    system("pause");
    return 0;
}