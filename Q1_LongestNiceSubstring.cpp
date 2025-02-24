#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if (n < 2) return "";
        unordered_set<char> st(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            if (st.count(tolower(s[i])) && st.count(toupper(s[i]))) continue;
            string s1 = longestNiceSubstring(s.substr(0, i));
            string s2 = longestNiceSubstring(s.substr(i + 1));
            return s1.size() >= s2.size() ? s1 : s2;
        }
        return s;
    }
};

int main() {
    Solution sol;
    string s = "YazaAay";
    cout << sol.longestNiceSubstring(s) << endl;
    return 0;
}
