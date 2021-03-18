#include <iostream>
#include <stack>
using namespace std;

#define RANGE 100
#define OK 1
#define ERROR 0

int R[10][10] = {
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 0, 0, 1, 1, 1},
    {0, 1, 0, 0, 1, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
    {0, 1, 0, 1, 1, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 1, 0}};

typedef struct
{
    int m, n;
    int arr[RANGE][RANGE];
} map; //地图结构

void initmap(map &map, int a[10][10], int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            map.arr[i][j] = a[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= row + 1; i++)
    {
        map.arr[i][0] = map.arr[i][col + 1] = 1;
    }
    for (int j = 0; j <= col + 1; j++)
    {
        map.arr[0][j] = map.arr[row + 1][j] = 1;
    }
    map.m = row + 1;
    map.n = col + 1;
}

void print(map map)
{
    int i, j;
    for (i = 0; i <= map.m; i++)
    {
        for (j = 0; j <= map.n; j++)
        {
            switch (map.arr[i][j])
            {
            case 0:
                printf("  "); //没有走过
                break;
            case 1:
                printf(" #"); //障碍
                break;
            case 2:
                printf(" *"); //走过且走的通
                break;
            case 3:
                printf(" @"); //走过但不通
                break;
            }
        }
        printf("\n");
    }
}

typedef struct point
{
    int x, y;
} point;

typedef struct elemtype
{
    int ord;
    point p;
    int di;
} elemtype;

bool pass(map map, point p)
{ //判断是否能通过，是否为未曾走到过的方块
    if (map.arr[p.y][p.x] == 0)
        return true;
    else
        return false;
}

void footprint(map &map, point p)
{ //留下足迹
    map.arr[p.y][p.x] = 2;
}

point nextpoint(point &p, int di)
{ //下一个位置
    switch (di)
    {
    case 1:
        p.x++;
        break;
    case 2:
        p.y++;
        break;
    case 3:
        p.x--;
        break;
    case 4:
        p.y--;
        break;
    }
    return p;
}

void markprint(map &map, point p)
{ //不能通过的标记
    map.arr[p.y][p.x] = 3;
}

bool pointcmp(point m, point n)
{
    if (m.x == n.x && m.y == n.y)
        return true;
    else
        return false;
}

bool mazepath(map &map, point start, point end)
{
    stack<elemtype> s;
    point currentpoint = start;
    int currentstep = 1;
    do
    {
        if (pass(map, currentpoint))
        {
            footprint(map, currentpoint);
            elemtype e = {currentstep, currentpoint, 1};
            s.push(e);
            if (pointcmp(currentpoint, end))
            {
                printf("可通过\n");
                return true;
            }
            currentpoint = nextpoint(currentpoint, 1);
            currentstep++;
        }
        else
        {
            if (!s.empty())
            {
                elemtype e = s.top();
                s.pop();
                while ((e.di == 4) && (!s.empty()))
                {
                    markprint(map, e.p);
                    e = s.top();
                    s.pop();
                }
                if (e.di < 4)
                {
                    e.di++;
                    s.push(e);
                    currentpoint = nextpoint(e.p, e.di);
                }
            }
        }
    } while (!s.empty());
    printf("不可通过\n");
    return false;
}

int main()
{
    map map;
    initmap(map, R, 10, 10);
    print(map);
    point start = {1, 1};
    point end = {10, 10};
    mazepath(map, start, end);
    print(map);
    system("pause");
    return 0;
}