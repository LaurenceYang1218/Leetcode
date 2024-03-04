class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }
        for (int j = 1; j <= m; j++) {
            if (j > 1 && p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }else if (p[j-1] == '*') {
                    if (s[i-1] == p[j-2] || p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j];
                    }
                    dp[i][j] = dp[i][j] |  dp[i][j-2];
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        return dp[n][m];
    }
};