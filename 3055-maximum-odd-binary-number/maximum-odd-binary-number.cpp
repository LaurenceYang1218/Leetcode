class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                oneCnt++;
            }
        }
        string ans = "";
        for (int i = 0; i < oneCnt-1; i++) {
            ans += '1';
        }
        for (int i = oneCnt; i < s.length(); i++) {
            ans += '0';
        }
        ans += '1';
        return ans;
    }
};