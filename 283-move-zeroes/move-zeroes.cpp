class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        for (right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};