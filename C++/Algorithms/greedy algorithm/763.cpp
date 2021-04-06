#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> last(26, 0);
        vector<int> result;
        auto length = S.length();
        for (int i = 0; i < length; i++)
        {
            last[S[i] - 'a'] = i;
        }
        int head, end;
        head = 0;
        end = last[S[0] - 'a'];
        for (int i = 0; i < length; i++)
        {
            if (end < last[S[i] - 'a'])
            {
                end = last[S[i] - 'a'];
            }
            if (end == i)
            {
                result.push_back(end - head + 1);
                head = end + 1;
            }
        }
        return result;
    }
};

int main()
{
    string S;
    cin >> S;
    Solution a;
    vector<int> b;
    b = a.partitionLabels(S);
    for (auto it : b)
    {
        cout << it << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}