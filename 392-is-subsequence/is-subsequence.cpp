class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool ans = false;
        int i = 0, j = 0;
        for (i = 0; i < t.length(); i++) {
            if (s[j] == t[i]) {
                j++;
            }
        }
        if (j == s.length()) {
            ans = true;
        } 
        return ans;
    }
};