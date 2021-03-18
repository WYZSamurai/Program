#include <iostream>
#include <stack>
using namespace std;

void clear(stack<char> &s)
{
    while (!s.empty())
    {
        s.pop();
    }
}

void print(stack<char> s)
{
    stack<char> p;
    while (!s.empty())
    {
        p.push(s.top());
        s.pop();
    }
    while (!p.empty())
    {
        s.push(p.top());
        p.pop();
        printf("%c", s.top());
    }
    printf("\n");
}

void lineedit()
{
    stack<char> s;
    char c = getchar();
    while (c != EOF)
    {
        while (c != EOF && c != '\n')
        {
            switch (c)
            {
            case '#':
                s.pop();
                break;
            case '@':
                clear(s);
                break;
            default:
                s.push(c);
                break;
            }
            c = getchar();
        }
        print(s);
        clear(s);
        if (c != EOF)
            c = getchar();
    }
    clear(s);
}

int main()
{
    lineedit();

    system("pause");
    return 0;
}