#include <iostream>
#include <stack>
using namespace std;

char r[7][7] = { {'>', '>', '<', '<', '<', '>', '>'},
                {'>', '>', '<', '<', '<', '>', '>'},
                {'>', '>', '>', '>', '<', '>', '>'},
                {'>', '>', '>', '>', '<', '>', '>'},
                {'<', '<', '<', '<', '<', '=', '0'},
                {'>', '>', '>', '>', '0', '>', '>'},
                {'<', '<', '<', '<', '<', '0', '='} };

int match(char a)
{
    int i;
    switch (a)
    {
    case '+':
        i = 0;
        break;
    case '-':
        i = 1;
        break;
    case '*':
        i = 2;
        break;
    case '/':
        i = 3;
        break;
    case '(':
        i = 4;
        break;
    case ')':
        i = 5;
        break;
    case '#':
        i = 6;
        break;
    }
    return i;
}

char fun(char a, char b)
{
    int i, j;
    i = match(a);
    j = match(b);
    return r[i][j];
}

char signlist[7] = { '+', '-', '*', '/', '(', ')', '#' };

bool in(char a, char c[])
{
    for (int i = 0; i < 7; i++)
    {
        if (a == c[i])
            return true;
    }
    return false;
}

double operat(stack<char>& sign, stack<double>& num)
{
    char c = sign.top();
    sign.pop();
    double b = num.top();
    num.pop();
    double a = num.top();
    num.pop();
    double i;
    switch (c)
    {
    case '+':
        i = a + b;
        break;
    case '-':
        i = a - b;
        break;
    case '*':
        i = a * b;
        break;
    case '/':
        i = a / b;
        break;
    }
    num.push(i);
    return i;
}

void mainfun()
{
    stack<char> sign;
    stack<double> num;
    sign.push('#');
    char c = getchar();
    while (c != '#' || sign.top() != '#')
    {
        if (!in(c, signlist))
        {
            double i = c - '0';
            num.push(i);
            c = getchar();
        }
        else
        {
            switch (fun(sign.top(), c))
            {
            case '<':
                sign.push(c);
                c = getchar();
                break;
            case '>':
                operat(sign, num);
                break;
            case '=':
                sign.pop();
                c = getchar();
                break;
            }
        }
    }
    cout << num.top() << endl;
}

int main()
{
    mainfun();
    system("pause");
    return 0;
}