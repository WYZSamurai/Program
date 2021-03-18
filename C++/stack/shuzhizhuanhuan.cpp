#include <iostream>
#include <stack>
using namespace std;

void conversion()
{
    stack<char> s;
    int x;
    cout << "Enter the Base: " << endl;
    cin >> x;
    int d;
    cout << "Enter the Number: " << endl;
    cin >> d;
    while (d)
    {
        int y = d % x;
        char c;
        if (y > 9)
        {
            c = 'a' + y - 10;
        }
        else
        {
            c = '0' + y;
        }
        s.push((c)); // ำเสýฝ๘ีป
        d = d / x;   // ณýสý
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    printf("\n");
}

int main()
{
    conversion();

    system("pause");
    return 0;
}