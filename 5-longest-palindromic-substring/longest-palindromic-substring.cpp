class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) {
            return s;
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int leftIdx = 0, rightIdx = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                leftIdx = i;
                rightIdx = i+1;
            }
        }
        for (int d = 2; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                int j = i + d;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    leftIdx = i;
                    rightIdx = j;
                }
            }
        }
        return s.substr(leftIdx, rightIdx-leftIdx+1);
    }
};