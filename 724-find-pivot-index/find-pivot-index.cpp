class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1, sum = 0, preSum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        for (int i = 0; i < nums.size(); i++) {
            if (preSum == sum - preSum - nums[i]) {
                ans = i;
                break;
            }
            preSum += nums[i];
        }
        return ans;
    }
};