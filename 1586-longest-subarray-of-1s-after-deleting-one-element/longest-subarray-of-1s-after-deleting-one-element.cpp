class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int ans = 0, isZero = 0;
        for (r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                isZero++;
            }
            if (isZero > 1) {
                if (nums[l] == 0) {
                    isZero--;
                }
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};