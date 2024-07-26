class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int cnt = 1, loopCnt = 0;
        
        for (int idx = n-1; idx > 0; idx -= 2) {
            for (int j = 0; j < idx; j++) {
                res[loopCnt][j+loopCnt] = cnt++;
            }
            for (int j = 0; j < idx; j++) {
                res[j+loopCnt][n-1-loopCnt] = cnt++;
            }
            for (int j = idx; j >= 1; j--) {
                res[n-1-loopCnt][j+loopCnt] = cnt++;
            }
            for (int j = idx; j >= 1; j--) {
                res[j+loopCnt][loopCnt] = cnt++;
            }
            loopCnt++;
        }
        if (n % 2 == 1) {
            res[loopCnt][loopCnt] = cnt;
        }

        // for (size_t i = 0; i < res.size(); i++) {
        //     for (size_t j = 0; j < res.size(); j++) {
        //         cout << res[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        return res;
    }
};