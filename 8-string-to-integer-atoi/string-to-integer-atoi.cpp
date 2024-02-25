class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, idx = 0;
        while (idx < s.length() && s[idx] == ' ') {
            idx++;
        }
        if (idx < s.length() && s[idx] == '+') {
            sign = 1;
            idx++;
        }else if (idx < s.length() && s[idx] == '-') {
            sign = -1;
            idx++;
        }
        int ans = 0;
        while(idx < s.length() && isdigit(s[idx])) {
            if ((ans > INT_MAX/10) || (ans == INT_MAX/10 && (s[idx]-'0') > INT_MAX%10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + (s[idx]-'0');
            idx++;
        }
        return sign * ans;
    }
};