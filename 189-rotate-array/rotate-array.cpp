class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = tmp[i];
        }
        return;
    }
};