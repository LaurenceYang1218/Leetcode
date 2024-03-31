class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int maxIdx = -1, minIdx = -1, bound = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxK || nums[i] < minK) {
                bound = i;
            }
            if (nums[i] == minK) {
                minIdx = i;
            }
            if (nums[i] == maxK) {
                maxIdx = i;
            }
            ans += max(0, min(minIdx, maxIdx) - bound);
        }
        return ans;
    }
};