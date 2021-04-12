#include <iostream>
#include <cstring>
using namespace std;

#define increase 1

char *enterstr()
{
    //每输一个字符便加一个内存
    char *s;
    s = (char *)malloc(sizeof(char));
    int size = 1;
    int i = 0;
    while ((s[i] = getchar()) != '\n')
    {
        i++;
        s = (char *)realloc(s, (size + increase) * sizeof(char));
        size += increase;
    }
    s[size - 1] = 0;
    return s;
}

int main()
{
    char *s;
    s = enterstr();
    cout << s << endl;
    //cout << strlen(s) << endl;

    system("pause");
    return 0;
}