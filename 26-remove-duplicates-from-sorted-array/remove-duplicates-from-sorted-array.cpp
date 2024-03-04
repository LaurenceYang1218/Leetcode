class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[curr] = nums[i];
                curr++;
            }
        }
        return curr;
    }
};