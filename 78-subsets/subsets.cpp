class Solution {
public:
    vector<vector<int>> output;
    void backtrack(int currIdx, vector<int>& nums, vector<int>& curr, int size) {
        if (curr.size() == size) {
            output.push_back(curr);
            return;
        }
        for (int i = currIdx; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, size);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> curr;
            backtrack(0, nums, curr, i);
        }
        return output;
    }
};