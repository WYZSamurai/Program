#include <cstdio>
#include <cstdlib>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAX 100     //初始分配内存
#define increase 10 //分配增量

typedef struct sql
{
    //定义线性表
    int *base;    //基址
    int length;   //当前长度
    int listsize; //当前的储存容量（sizeof(int)），总长度
} SqList;

int Initial_sq(SqList &L)
{
    //初始化空的线性表
    L.base = (int *)malloc(MAX * sizeof(int)); //分配字节空间
    if (!L.base)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = MAX;
    return OK;
}

int list_insert(SqList &L, int i, int elem)
{
    //在第i个位置之前插入元素elem，时间复杂度O(n)
    if (i < 1 || i > L.length + 1)
        return ERROR; //i值不合法
    if (L.length >= L.listsize)
    { //空间已满，增加分配
        L.base = (int *)realloc(L.base, (L.listsize + increase) * sizeof(int));
        if (!L.base)
            exit(ERROR);
        L.listsize += increase;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.base[j] = L.base[j - 1];
    }
    L.base[i - 1] = elem;
    L.length++; //当前长度加一
    return OK;
}

int list_delete(SqList &l, int i, int *e)
{
    //删除第i个元素，并用e返回其值，时间复杂度O(n)
    if (i < 1 || i > l.length + 1)
        return ERROR;
    *e = l.base[i - 1];
    for (int j = i; j < l.length; j++)
    {
        l.base[j - 1] = l.base[j];
    }
    l.length--;
    return OK;
}

void list_print(SqList &l)
{
    printf("length=%d,listsize=%d.\n", l.length, l.listsize);
    for (int i = 0; i < l.length; i++)
    {
        printf("%d\n", l.base[i]);
    }
}

int compare(int a, int b)
{
    if (a == b)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int list_search(SqList &l, int e, int (*compare)(int a, int b))
{
    int i = 1;
    int *p;
    p = l.base;
    while (i <= l.length && !(*compare)(*p++, e))
        i++;
    if (i <= l.length)
        return i;
    else
        return 0;
}