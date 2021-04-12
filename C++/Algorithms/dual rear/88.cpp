#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        vector<int> result(len);
        int rear1 = 0;
        int rear2 = 0;
        int rear3 = 0;
        if(m == 0 && n != 0){
            cout << '[';
            for (int i = 0;i < n - 1;i++) {
                cout << nums2[i] << ',';
                
            }
            cout << nums2[n - 1];
            cout << ']';
            return;
        }
        if (n == 0) {
            cout << '[';
            for (int i = 0;i < m - 1;i++) {
                cout << nums1[i] << ',';
                
            }
            cout << nums1[m - 1];
            cout << ']';
            return;
        }
        while (rear1 <= m && rear2 <= n) {
            if (rear1 == m && rear2 < n) {
                result[rear3] = nums2[rear2];
                rear3++;
                rear2++;
                continue;
            }
            if (rear2 == n && rear1 < m) {
                result[rear3] = nums1[rear1];
                rear1++;
                rear3++;
                continue;
            }
            if (nums1[rear1] <= nums2[rear2]) {
                result[rear3] = nums1[rear1];
                rear3++;
                rear1++;
            }
            else {
                result[rear3] = nums2[rear2];
                rear3++;
                rear2++;
            }
        }
        cout << '[';
        for (int i = 0;i < len - 1;i++) {
            cout << result[i] << ',';
        }
        cout << result[len - 1] << ']';
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);
    for (int i = 0;i < m;i++) {
        int t;
        cin >> t;
        nums1[i] = t;
    }
    for (int i = 0;i < n;i++) {
        int t;
        cin >> t;
        nums2[i] = t;
    }
    Solution s;
    s.merge(nums1, m, nums2, n);

    system("pause");
    return 0;
}