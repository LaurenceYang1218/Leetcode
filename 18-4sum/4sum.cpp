class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int k = j+1, l = nums.size()-1;
                while (k < l) {
                    long long curSum = nums[i];
                    curSum += nums[j];
                    curSum += nums[k];
                    curSum += nums[l];
                    if (curSum > target) {
                        l--;
                    }else if (curSum < target) {
                        k++;
                    }else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < l && nums[k] == nums[k+1]) {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l-1]) {
                            l--;
                        }
                        k++;
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};