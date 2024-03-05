class Solution {
public:
    bool isIncrease(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                return false;
            }
        }
        return true;
    }

    bool isDecrease(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                return false;
            }
        }
        return true;
    }

    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        return isDecrease(nums) || isIncrease(nums);
    }
};