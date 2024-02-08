class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        int sqrtIdx = (int)sqrt(n) + 1;
        vector<int> squares(sqrtIdx, 0);
        dp[0] = 0;
        for (int i = 1; i < sqrtIdx; i++) {
            squares[i] = i * i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < sqrtIdx; j++) {
                if (i < squares[j]) {
                    break;
                }
                dp[i] = min(dp[i], dp[i - squares[j]] + 1);
            }
        }
        return dp[n];
    }
};