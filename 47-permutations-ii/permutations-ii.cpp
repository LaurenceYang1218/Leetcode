class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, int> numMap;
    void solve(int start, vector<int> nums, vector<int> vec, int currLen) {
        if (currLen == nums.size()) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            if (numMap[nums[i]] == 0) {
                continue;
            }
            vec.push_back(nums[i]);
            numMap[nums[i]]--;
            solve(start, nums, vec, currLen + 1);
            vec.pop_back();
            numMap[nums[i]]++;
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]]++;
        }
        solve(0, nums, vec, 0);
        return ans;
    }   
};