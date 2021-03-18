#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

#define OK 1
#define ERROR 0
#define MAX 100

int pipei(stack<char> &s, char *str)
{
    s.push('a');
    for (int i = 0; i < strlen(str); i++)
    {
        int a = str[i];
        if (a == '(' || a == '{' || a == '[')
        {
            s.push(a);
        }
        else if ((a == ')' && s.top() == '(') || (a == '}' && s.top() == '{') || (a == ']' && s.top() == '['))
        {
            s.pop();
        }
    }
    s.pop();
    if (s.empty())
    {
        printf("ok\n");
        return OK;
    }
    else
    {
        printf("error\n");
        return ERROR;
    }
    //printf("Stack's Size = %d\n", s.size());
    return OK;
}

int main()
{
    stack<char> s;
    char *c = (char *)malloc(MAX * sizeof(char));
    scanf("%s", c);
    printf("c's Length = %d\n", strlen(c));
    pipei(s, c);

    system("pause");
    return 0;
}