class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS_len(n, 1);
        vector<int> LDS_len(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    LIS_len[i] = max(LIS_len[i], LIS_len[j] + 1);
                }
            }
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= i; j--) {
                if (nums[i] > nums[j]) {
                    LDS_len[i] = max(LDS_len[i], LDS_len[j] + 1);
                }
            }
        }
        int ret = n;
        for (int i = 0; i < n; i++) {
            if (LIS_len[i] > 1 && LDS_len[i] > 1) {
                ret = min(ret, n - LIS_len[i] - LDS_len[i] + 1);
            }
        }
        return ret; 
    }
};