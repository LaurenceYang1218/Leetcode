class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> um;
        um[nums[0]] = 0;
        long long prefixSum = 0, ans = LONG_LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            auto it = um.find(nums[i] - k);
            if (it != um.end()) {
                ans = max(ans, prefixSum - it->second);
            }
            it = um.find(nums[i] + k);
            if (it != um.end()) {
                ans = max(ans, prefixSum - it->second);
            }
            if (i+1 < nums.size()) {
                it = um.find(nums[i+1]);
                if (it == um.end() || it->second > prefixSum) {
                    um[nums[i+1]] = prefixSum;
                }
            }
        }
        return ans == LONG_LONG_MIN ? 0 : ans;
    }
};