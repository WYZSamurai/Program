#include <iostream>
#include <stack>
using namespace std;

void move(int a, char x, char y)
{
}

void hanoi(int n, char A, char B, char C)
{
    if (n <= 1)
    {
        printf("1 move %c to %c\n", A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    printf("%d move %c to %c \n", n, A, C);
    hanoi(n - 1, B, A, C);
}

int main()
{
    char x, y, z;
    x = 'X';
    y = 'Y';
    z = 'Z';
    int n;
    cin >> n;
    hanoi(n, x, y, z);
    system("pause");
    return 0;
}