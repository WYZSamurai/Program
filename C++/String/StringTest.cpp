#include <iostream>
#include <string>
#include <cstring> //strcmp strcpy strcat
using namespace std;

void StrAssign(string &s, char *c)
{
    //����ֵΪc�Ĵ�s
    s.assign(c);
}

void StrCopy(string &s, string t)
{
    //char a[];
    //t.copy(a, a.length());
}

int main()
{
    string s = "ferfrf";
    printf("%s\n", s.c_str());

    system("pause");
    return 0;
}