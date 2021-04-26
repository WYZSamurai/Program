#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {

    }

    ListNode(int x) {
        this->val = x;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
    }
};

int main() {
    ListNode l[10010];
    int n;
    cin >> n;
    for (int i = 0;i < n;++i) {
        int val;
        cin >> val;
        l[i] = ListNode(val);
        if (i > 0) {
            l[i - 1].next = l[i].next;
        }
    }
    int pos;
    cin >> pos;
    if (pos != -1) {
        l[n - 1].next = &l[pos];
        //cout << l[n - 1].next->val << endl;
    }
    /*
    for (int i = 0;i < n;++i) {
        cout << l[i].val << ' ';
    }
    cout << endl;
    */

    Solution s;
    s.detectCycle(l);

    system("pause");
    return 0;
}