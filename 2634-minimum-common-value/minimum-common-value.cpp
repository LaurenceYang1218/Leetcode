class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1;
        for (int i = 0; i < nums1.size(); i++) {
            auto it = lower_bound(nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end() && *it == nums1[i]) {
                ans = nums1[i];
                break;
            }
        }
        return ans;
    }
};