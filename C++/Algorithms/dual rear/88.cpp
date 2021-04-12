#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    }
};

int main() {
    int len1, len2, m, n;
    cin >> len1 >> len2 >> m >> n;
    vector<int> nums1(len1);
    vector<int> nums2(len2);
    for (int i = 0;i < len1;i++) {
        int t;
        cin >> t;
        nums1[i] = t;
    }
    for (int i = 0;i < len2;i++) {
        int t;
        cin >> t;
        nums2[i] = t;
    }
    Solution s;
    s.merge(nums1, m, nums2, n);
    //
    system("pause");
    return 0;
}