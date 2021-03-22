#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct event
{
    int now;
    int type;
} event;

typedef struct persontype
{
    int arrivaltime;
    int duringtime;
} persontype;

vector<event> eventlist;
event en;
queue<persontype> q[5];
persontype person;
int totaltime, number, closetime;

int cmp(event a, event b)
{
    if (a.now < b.now)
        return -1;
    else if (a.now == b.now)
        return 0;
    else
        return 1;
}

void show()
{
}

int ordertinsert(vector<event> &eventlist, event en, int(cmp)(event, event))
{
    auto it = eventlist.begin();
    if (it.base() == NULL)
        return 0;
    for (it; (it + 1).base() != NULL && cmp(*(it + 1), en); it++)
    {
    }
    eventlist.insert(it, en);
    return 1;
}

void openforday()
{
    totaltime = 0;
    number = 0;
    en.now = 0;
    en.type = 0;
    closetime = 480;
    ordertinsert(eventlist, en, cmp);
}

void closeforday()
{
    cout << "totalnumber = " << number << " time = " << totaltime / number << endl;
}

void arrive()
{
    number++;
}

void Ramdom(int &a, int &b)
{
}

int main()
{
    system("pause");
    return 0;
}