class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return len;
        }
        int i = 1,j = 1, cnt = 1;
        while (i < len) {
            if (nums[i] == nums[i-1]) {
                cnt++;
                if (cnt > 2) {
                    i++;
                    continue;
                }            
            }else {
                cnt = 1;
            }
            nums[j++] = nums[i++];
        }
        return j;
    }
};