class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        vector<int> maxNums(nums.size(), 0);
        if (nums.size() == 1) {
            ans = nums[0];
        }else if (nums.size() == 2) {
            ans = max(nums[0], nums[1]);
        }else {
            maxNums[0] = nums[0];
            maxNums[1] = max(nums[0], nums[1]);
            for (int i = 2; i < nums.size(); i++) {
                maxNums[i] = max(maxNums[i-1], maxNums[i-2] + nums[i]);
            }
            ans = maxNums[nums.size()-1];
        }
        return ans;
    }
};