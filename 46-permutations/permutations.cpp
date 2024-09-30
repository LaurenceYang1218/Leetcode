class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& vec, int currLen) {
        if (currLen == nums.size()) {
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(vec.begin(), vec.end(), nums[i]) == vec.end()) {
                vec.push_back(nums[i]);
                solve(nums, vec, currLen + 1);
                vec.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vec;
        solve(nums, vec, 0);
        return ans;
    }
};