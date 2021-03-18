#include <iostream>
#include <stack>
using namespace std;

typedef struct elemtype
{
    int a;
} elemtype;

void init(stack<elemtype> &s)
{
}

elemtype gettop(stack<elemtype> s)
{
    elemtype e = s.top();
    return e;
}

void Push(stack<elemtype> &s, elemtype e)
{
    s.push(e);
}

elemtype Pop(stack<elemtype> &s)
{
    elemtype e = s.top();
    s.pop();
    return e;
}

void clearstack(stack<elemtype> &s)
{
    while (!s.empty())
    {
        s.pop();
    }
}

bool stackempty(stack<elemtype> s)
{
    if (s.empty())
        return true;
    else
        return false;
}

void print(stack<elemtype> s)
{
    stack<elemtype> p;
    while (!s.empty())
    {
        p.push(s.top());
        s.pop();
    }
    while (!p.empty())
    {
        s.push(p.top());
        p.pop();
        printf("");
    }
    printf("\n");
}