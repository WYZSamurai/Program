#include<iostream>
#include<string>
using namespace std;

int main() {

    int t;
    cin >> t;
    string s[t];
    for (int i = 0;i < t;++i) {
        cin >> s[i];
        s[i] = s[i] + "0";
    }
    int res[t] = { 0 };
    for (int i = 0;i < t;i++) {
        int len = s[i].length();
        for (int j = 0;j < len + 1;j++) {
            if (s[i][j] == '1' && s[i][j + 1] == '0') {
                res[i]++;
            }
        }
    }
    for (int i = 0;i < t;i++) {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}