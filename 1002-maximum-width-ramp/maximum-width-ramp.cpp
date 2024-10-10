class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> idxStack;
        for (int i = 0; i < nums.size(); i++) {
            if (idxStack.empty() || nums[idxStack.top()] > nums[i]) {
                idxStack.push(i);
            }
        }
        int ret = 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            while (!idxStack.empty() && nums[idxStack.top()] <= nums[i]) {
                ret = max(ret, i - idxStack.top());
                idxStack.pop();
            }
        }        
        return ret;
    }
};