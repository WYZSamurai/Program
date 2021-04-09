#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> res(2);
    int len = numbers.size();
    vector<int> a(2200, 1001);
    for (int i = 0; i <= len - 2; i++)
    {
        if (a[numbers[i] + 1000] == numbers[i])
            continue;
        int other = target - numbers[i];
        int cunzai = 0;
        for (int j = i + 1; j <= len - 1; j++)
        {
            if (numbers[j] == other)
            {
                res[0] = i + 1;
                res[1] = j + 1;
                cunzai = 1;
            }
        }
        if (cunzai == 0)
            a[numbers[i] + 1000] = numbers[i];
    }

    return res;
}

int main()
{
    vector<int> numbers;
    int target;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    cin >> target;
    vector<int> res;
    res = twoSum(numbers, target);
    cout << res[0] << ',' << res[1] << endl;

    system("pause");
    return 0;
}