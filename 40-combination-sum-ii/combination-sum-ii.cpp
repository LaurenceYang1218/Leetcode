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
            if (i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            vec.push_back(candidates[i]);
            solve(i+1, candidates, vec, target-candidates[i]);
            vec.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        solve(0, candidates, vec, target);
        return ans;
    }
};