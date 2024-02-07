class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0, ptr = 0;
        vector<int> nums(m + n, 0);
        while (ptr1 < m || ptr2 < n) {
            if (ptr1 == m) {
                nums[ptr] = nums2[ptr2++];
            }else if (ptr2 == n) {
                nums[ptr] = nums1[ptr1++];
            }else {
                if (nums1[ptr1] < nums2[ptr2]) {
                    nums[ptr] = nums1[ptr1++];
                }else {
                    nums[ptr] = nums2[ptr2++];
                }
            }
            ptr++;
        }
        nums1 = nums;
        return;
    }
};