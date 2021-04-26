#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
用快慢指针（floyd判圈法）
快指针走两步，慢指针走一步
*/

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
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            if (!fast || !(fast->next))return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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
            l[i - 1].next = &l[i];
        }
    }
    int pos;
    cin >> pos;
    if (pos != -1) {
        l[n - 1].next = &l[pos];
        //cout << l[n - 1].next->val << endl;
    }

    Solution s;
    //int val = s.detectCycle(l)->val;
    //cout << val << endl;

    system("pause");
    return 0;
}