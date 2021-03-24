#include <iostream>
#include <vector>
using namespace std;

bool func(vector<int> &flower, int n)
{
    int n1 = 0;
    int length = flower.size();
    flower.insert(flower.begin(), 0);
    flower.push_back(0);
    for (int i = 1; i <= length; i++)
    {
        if ((flower[i - 1] == 0) && (flower[i + 1] == 0) && (flower[i] == 0))
        {
            n1++;
            flower[i] = 1;
        }
    }
    if (n1 >= n)
        return true;
    else
        return false;
}

int main()
{
    int m;
    cin >> m;
    vector<int> flower;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        flower.push_back(x);
    }
    int n;
    cin >> n;
    if (func(flower, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    m = flower.size();
    for (int i = 1; i < m - 1; i++)
    {
        cout << flower[i] << ' ';
    }
    cout << endl;

    system("pause");
    return 0;
}

/* */