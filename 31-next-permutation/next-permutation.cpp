class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 2;
        while (idx >= 0 && nums[idx+1] <= nums[idx]) {
            idx--;
        }
        if (idx >= 0) {
            int i = nums.size()-1;
            while (nums[i] <= nums[idx]) {
                i--;
            }
            swap(nums[idx], nums[i]);
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }

};