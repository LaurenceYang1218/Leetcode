class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        unsigned int total = mean * (n + m);
        unsigned int rollsSum = 0;
        for (int i = 0; i < m; i++) {
            rollsSum += rolls[i];
        }
        unsigned int remain = total - rollsSum;
        if (remain < n || remain > 6 * n) {
            return {};
        }
        int div = remain / n, mod = remain % n;
        vector<int> res(n, div);
        for (int i = 0; i < mod; i++) {
            res[i]++;
        }
        return res;
    }
};