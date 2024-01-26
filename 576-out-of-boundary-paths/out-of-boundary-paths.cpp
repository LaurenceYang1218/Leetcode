class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const unsigned int mod = 1e9 + 7;
        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
        dp[startRow][startColumn] = 1;
        int count = 0;
        for (int move = 0; move < maxMove; move++) {
            vector<vector<unsigned int>> temp(m, vector<unsigned int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0) 
                        count = (count + dp[i][j]) % mod;
                    if (j == 0) 
                        count = (count + dp[i][j]) % mod;   
                    if (i == m-1)
                        count = (count + dp[i][j]) % mod;   
                    if (j == n-1)
                        count = (count + dp[i][j]) % mod;   
                    temp[i][j] = ((i > 0 ? dp[i-1][j] : 0) + (i < m-1 ? dp[i+1][j] : 0)) % mod + 
                                ((j > 0 ? dp[i][j-1] : 0) + (j < n-1 ? dp[i][j+1] : 0)) % mod; 
                }
            }
            dp = temp;
        }   
        return count;
    }
};