class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) == numMap.end()) {
                numMap[target-nums[i]] = i;
            }else {
                ans.push_back(numMap[nums[i]]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};