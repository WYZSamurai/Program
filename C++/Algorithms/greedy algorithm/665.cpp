#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPossibility(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int x = nums[i], y = nums[i + 1];
        if (x > y)
        {
            nums[i] = y;
            if (is_sorted(nums.begin(), nums.end()))
            {
                return true;
            }
            nums[i] = x; // ¸´Ô­
            nums[i + 1] = x;
            return is_sorted(nums.begin(), nums.end());
        }
    }
    return true;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    if (checkPossibility(nums))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    system("pause");
    return 0;
}