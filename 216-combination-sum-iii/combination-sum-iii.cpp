class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, vector<int> vec, int currK, int target) {
        if (currK == 0) {
            if (target == 0) {
                ans.push_back(vec);
            }
            return;
        }
        for (int i = start; i <= 9; i++) {
            vec.push_back(i);
            solve(i+1, vec, currK-1, target-i);
            vec.pop_back();
        }
        return;
    }   
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        solve(1, vec, k, n);
        return ans;
    }
};