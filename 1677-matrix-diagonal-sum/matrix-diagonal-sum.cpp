class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        if (n % 2 == 0) {
            for (int i = 0; i < n; i++) {
                sum += mat[i][i];
                sum += mat[n-1-i][i];
            }
        }else {
            for (int i = 0; i < n; i++) {
                sum += mat[i][i];
                sum += mat[n-1-i][i];
            }
            sum -= mat[n/2][n/2];
        }
        return sum;
    }
};