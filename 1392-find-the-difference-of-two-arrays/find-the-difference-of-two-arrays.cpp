class Solution {
public:
    vector<int> getElements(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> inNums1, inNums2;
        for (int i = 0; i < nums2.size(); i++) {
            inNums2.insert(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (inNums2.find(nums1[i]) == inNums2.end()) {
                inNums1.insert(nums1[i]);
            }
        }
        return vector<int>(inNums1.begin(), inNums2.end());
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElements(nums1, nums2), getElements(nums2, nums1)};
    }
};