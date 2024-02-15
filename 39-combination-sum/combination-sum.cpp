class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, vector<int> candidates, vector<int> vec, int target) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        }else if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            vec.push_back(candidates[i]);
            solve(i, candidates, vec, target-candidates[i]);
            vec.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        solve(0, candidates, vec, target);
        return ans;
    }
};