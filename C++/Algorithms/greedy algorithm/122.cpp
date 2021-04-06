#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int result = 0;
    int len = prices.size();
    int head, end;
    head = end = prices[0];
    for (int i = 1; i < len; i++)
    {
        if (end <= prices[i])
        {
            end = prices[i];
        }
        else
        {
            result += end - head;
            head = end = prices[i];
        }
        if (i == len - 1)
        {
            result += end - head;
        }
    }
    return result;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int add = maxProfit(v);
    cout << add << endl;

    system("pause");
    return 0;
}