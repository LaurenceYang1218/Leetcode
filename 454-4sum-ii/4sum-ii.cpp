class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                numMap[nums1[i]+nums2[j]]++;
            }
        }
        for (int k = 0; k < nums3.size(); k++) {
            for (int l = 0; l < nums4.size(); l++) {
                if (numMap.find(-nums3[k]-nums4[l]) != numMap.end()) {
                    cnt += numMap[-nums3[k]-nums4[l]];
                }
            }
        }
        return cnt;
    }
};