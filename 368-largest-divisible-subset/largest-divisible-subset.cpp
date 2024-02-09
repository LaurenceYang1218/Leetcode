class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int numsLen = nums.size();
        if (numsLen == 0) 
            return {};
        vector<vector<int>> eds(numsLen, vector<int>());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < numsLen; i++) {
            vector<int> maxSubset;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && maxSubset.size() < eds[j].size()) {
                    maxSubset = eds[j];
                }
            }
            eds[i].insert(eds[i].end(), maxSubset.begin(), maxSubset.end());
            eds[i].push_back(nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < numsLen; i++) {
            if (ans.size() < eds[i].size()) {
                ans = eds[i];
            }
        }
        return ans;
    }
};