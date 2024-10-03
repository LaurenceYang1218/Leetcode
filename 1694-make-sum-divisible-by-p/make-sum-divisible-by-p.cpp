class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum = (totalSum + nums[i]) % p;
        }
        int target = totalSum % p;
        if (target == 0) 
            return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int currSum = 0, ret = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            currSum = (currSum + nums[i]) % p;
            int needed = (currSum - target + p) % p;
            if (mp.find(needed) != mp.end()) {
                ret = min(ret, i - mp[needed]);
            }
            mp[currSum] = i;
        }
        return ret == nums.size() ? -1 : ret;
    }
};