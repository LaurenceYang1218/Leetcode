class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int currBits = __builtin_popcount(nums[0]);
        int currMaxNum = nums[0];
        int currMinNum = nums[0];
        int prevMaxNum = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == currBits) {
                currMaxNum = max(currMaxNum, nums[i]);
                currMinNum = min(currMinNum, nums[i]);
            }else {
                if (currMinNum < prevMaxNum) {
                    return false;
                }
                prevMaxNum = currMaxNum;
                currBits = __builtin_popcount(nums[i]);
                currMaxNum = nums[i];
                currMinNum = nums[i];
            }
        } 
        if (currMinNum < prevMaxNum) {
            return false;
        }
        return true; 
    }
};