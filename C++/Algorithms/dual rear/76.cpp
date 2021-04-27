#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int collect_min[26] = { 0 };
    int collect_max[26] = { 0 };
    string minWindow(string s, string t) {
        string none = "";
        string res[1000];
        find(t);
        int front = 0;
        int end = 0;
        int length[1000] = { 0 };
        bool isSearch = false;
        int i = 0;
        int res_i;

        int len = s.length();
        int len2 = t.length();

        while (end < len) {
            if (isSearch == false) {
                if (s[front] >= 'a') {
                    int temp = s[front] - 'a';
                    if (collect_min[temp] == 0) {
                        front++;
                        end = front;
                    }
                    else {
                        isSearch = true;
                        collect_min[temp]--;
                        res[i] += s[front];
                        end++;
                        len2--;
                    }
                }
                else {
                    int temp = s[front] - 'A';
                    if (collect_max[temp] == 0) {
                        front++;
                        end = front;
                    }
                    else {
                        isSearch = true;
                        collect_max[temp]--;
                        res[i] += s[front];
                        end++;
                        len2--;
                    }
                }
            }
            else {
                if (s[end] >= 'a') {
                    int temp = s[end] - 'a';
                    if (collect_min[temp] == 0) {
                        res[i] += s[end];
                        end++;
                    }
                    else {
                        collect_min[temp]--;
                        res[i] += s[end];
                        end++;
                        len2--;
                    }
                }
                else {
                    int temp = s[end] - 'A';
                    if (collect_max[temp] == 0) {
                        res[i] += s[end];
                        end++;
                    }
                    else {
                        collect_max[temp]--;
                        res[i] += s[end];
                        end++;
                        len2--;
                    }
                }
            }
            if (len2 == 0) {
                isSearch = false;
                length[i] = end - front;
                front = end;
                i++;
                len2 = t.length();
                find(t);
            }
        }
        //cout << res[0] << endl;
        //cout << length[0] << endl;
        
        if (length[0] == 0) {
            return none;
        }
        else if (i - 1 == 0) {
            res_i = 0;
        }
        else {
            for (i - 1;i > 0;i--) {
                res_i = (length[i] < length[i - 1]) ? i : i - 1;
            }
        }
        //cout << res_i << endl;

        return res[res_i];
    }
private:
    void find(string a) {
        int len = a.length();
        for (int i = 0;i < len;++i) {
            if (a[i] >= 'a') {
                int temp = a[i] - 'a';
                collect_min[temp]++;
            }
            else {
                int temp = a[i] - 'A';
                collect_max[temp]++;
            }
        }
    }
};

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    Solution test;
    cout << test.minWindow(s, t) << endl;

    system("pause");
    return true;
}