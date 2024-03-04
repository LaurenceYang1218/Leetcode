class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int currIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[currIdx++] = nums[i];
            }
        }
        return currIdx;
    }
};