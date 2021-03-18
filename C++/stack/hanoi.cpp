#include <iostream>
using namespace std;

void move(int a, char x, char y)
{
    printf("%d : %c -> %c\n", a, x, y);
}

void hanoi(int n, char A, char B, char C)
{
    if (n <= 1)
    {
        move(n, A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    move(n, A, C);
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