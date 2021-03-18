#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size < 2)
            return size;
        vector<int> v(size, 1);
        right(ratings, v);
        left(ratings, v);
        int x = accumulate(v.begin(), v.end(), 0);
        return x;
    }
    void right(vector<int> &rating, vector<int> &v)
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (rating[i] > rating[i - 1])
            {
                v[i] = v[i - 1] + 1;
            }
        }
    }
    void left(vector<int> &rating, vector<int> &v)
    {
        int size = rating.size();
        for (int i = size - 2; i >= 0; i--)
        {
            if (rating[i] > rating[i + 1])
            {
                v[i] = max(v[i], v[i + 1] + 1);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Solution s;
    cout << s.candy(v) << endl;
    system("pause");
    return 0;
}