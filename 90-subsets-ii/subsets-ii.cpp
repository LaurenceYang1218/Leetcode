class Solution {
public:
    vector<vector<int>> output;
    void backtrack(int currIdx, vector<int>& nums, vector<int>& curr, int size) {
        if (curr.size() == size) {
            output.push_back(curr);
            return;
        }
        for (int i = currIdx; i < nums.size(); i++) {
            if (i != currIdx && nums[i] == nums[i-1]) {
                continue;
            }
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr, size);
            curr.pop_back();
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++) {
            vector<int> curr;
            backtrack(0, nums, curr, i);
        }  
        return output;
    }
};