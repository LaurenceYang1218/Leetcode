class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        unordered_map<int, int> prefixMap;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (currSum == goal) {
                ans++;
            }
            if (prefixMap.find(currSum-goal) != prefixMap.end()) {
                ans += prefixMap[currSum-goal];
            }
            prefixMap[currSum]++;
        }
        return ans;
    }
};