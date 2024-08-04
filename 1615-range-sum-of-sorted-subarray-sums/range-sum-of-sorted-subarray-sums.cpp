class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> rangeSums;
        const int mod = 1e9+7;
        for(size_t i = 0; i < nums.size(); i++) {
            int tmpSum = 0;
            for (size_t j = i; j < nums.size(); j++) {
                tmpSum += nums[j];
                rangeSums.push_back(tmpSum);
            }
        }
        sort(rangeSums.begin(), rangeSums.end());
        int res = 0;
        for (int i = left-1; i < right; i++) {
            res += rangeSums[i];
            res %= mod;
        }
        return res;
    }
};