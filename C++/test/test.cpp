#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        int x = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= '0' && word[i] <= '9')
            {
                v.push_back(word[i]);
                x++;
            }
            else
            {
                x = 0;
            }
            if (x == 0)
                v.push_back(' ');
        }
        v.push_back(' ');
        vector<string> b;
        vector<char> a;

        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] >= '0' && v[i] <= '9')
            {
                a.push_back(v[i]);
                if (v[i + 1] == ' ')
                {
                    a.push_back(' ');
                    a.push_back(' ');
                    string temp;
                    int now = 0;
                    while(a[now] == '0'){
                        now++;
                    }
                    if(a[now] = ' ' && now > 0){
                        now--;
                    }
                    a.pop_back();
                    a.pop_back();
                    for (int j = now; j < a.size(); j++)
                    {
                        temp += a[j];
                    }
                    b.push_back(temp);
                    a.clear();
                }
            }
        }

        int n = 0;
        sort(b.begin(), b.end());
        for(auto it : b){
            cout << it << ' ';
        }
        for (int i = 0; i < b.size(); i++)
        {
            if ((i > 0) && (b[i - 1] == b[i]))
            {
                continue;
            }
            else
            {
                n++;
            }
        }
        cout << n;

        return n;
    }
};

int main()
{
    string word;
    cin >> word;
    Solution s;
    s.numDifferentIntegers(word);
    cout << endl;

    system("pause");
    return 0;
}