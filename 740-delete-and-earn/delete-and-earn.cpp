class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> numMap;
        int maxNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        vector<int> dp(maxNum+1, 0);
        dp[0] = 0;
        dp[1] = numMap[1];
        for (int i = 2; i <= maxNum; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + numMap[i]);
        }
        return dp[maxNum];
    }
};