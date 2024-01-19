class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        bool ans = false;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) {
                first = nums[i];
            }else if (nums[i] <= second) {
                second = nums[i];
            }else {
                ans = true;
            }
        }

        return ans;
    }
};