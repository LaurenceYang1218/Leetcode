class Solution {
public:
    int arraySign(vector<int>& nums) {
        int k = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                k *= -1;
            }else if (nums[i] == 0) {
                return 0;
            }
        }
        return k;
    }
};