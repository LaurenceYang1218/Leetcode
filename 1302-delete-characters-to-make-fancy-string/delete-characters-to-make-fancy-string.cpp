class Solution {
public:
    string makeFancyString(string s) {
        string ret = "";
        if (s.length() < 3) {
            return s;
        }
        ret += s[0];
        ret += s[1];
        for (int i = 2; i < s.length(); i++) {
            if (s[i] == s[i-1] && s[i-1] == s[i-2]) {
                continue;
            }
            ret += s[i];
        }
        return ret;
    }
};