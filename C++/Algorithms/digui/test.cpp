#include <iostream>
#include <stack>
using namespace std;

int a[10000];

/*int fact(stack<int> &s, int n)
{
    if (n == 0)
    {
        s.push(1);
        return 1;
    }
    else
    {
        int x = n * fact(s, n - 1);
        if (s.top() != x)
            s.push(x);
        return x;
    }
}*/

int fib(int n)
{
    if (a[n] != 0)
        return a[n];
    if (n < 2)
    {
        return a[n] = n;
    }
    if (n > 1)
    {
        return a[n] = fib(n - 1) + fib(n - 2);
    }
    return 0;
}

int ack(int m,)

void print(stack<int> s)
{
    stack<int> p;
    while (!s.empty())
    {
        p.push(s.top());
        s.pop();
    }
    while (!p.empty())
    {
        s.push(p.top());
        p.pop();
        printf("%d ", s.top());
    }
    printf("\n");
}

int main()
{
    int n;
    cin >> n;
    fib(n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}