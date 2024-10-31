class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] > grid[i][j-1] && dp[i][j-1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
                }
                if (i-1 >= 0 && grid[i][j] > grid[i-1][j-1] && dp[i-1][j-1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
                if (i+1 < m && grid[i][j] > grid[i+1][j-1] && dp[i+1][j-1] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 1);
                }
                ret = max(ret, dp[i][j]-1);
            }
        }
        return ret;
    }
};