class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
            return 0;
        }
        dp[0][0] = 1;
        bool rowBlock = false, colBlock = false;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1 || rowBlock) {
                dp[i][0] = 0;
                rowBlock = true;   
            }else {
                dp[i][0] = 1;
            }
        }

        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1 || colBlock) {
                dp[0][j] = 0;
                colBlock = true;
            }else {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};