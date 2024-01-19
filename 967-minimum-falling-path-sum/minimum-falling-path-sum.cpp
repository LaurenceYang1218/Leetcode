class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix.size()+1, 0));
        for (int row = matrix.size()-1; row >= 0; row--) {
            for (int col = 0; col < matrix.size(); col++) {
                if (col == 0) {
                    dp[row][col] = min(dp[row+1][col], dp[row+1][col+1]) + matrix[row][col];
                }else if (col == matrix.size()-1) {
                    dp[row][col] = min(dp[row+1][col-1], dp[row+1][col]) + matrix[row][col];
                }else {
                    dp[row][col] = min(dp[row+1][col-1], min(dp[row+1][col], dp[row+1][col+1])) + matrix[row][col];
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};