class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++) {
            if (um.find(target-nums[i]) == um.end()) {
                um.insert({nums[i], i});
            }else {
                res.push_back(um[target-nums[i]]);
                res.push_back(i);
            }
        }
        return res;
    }
};