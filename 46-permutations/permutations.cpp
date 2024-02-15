class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, vector<int> nums, vector<int> vec, int currLen) {
        if (currLen == nums.size()) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (find(vec.begin(), vec.end(), nums[i]) == vec.end()) {
                vec.push_back(nums[i]);
                solve(start, nums, vec, currLen + 1);
                vec.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        solve(0, nums, vec, 0);
        return ans;
    }
};