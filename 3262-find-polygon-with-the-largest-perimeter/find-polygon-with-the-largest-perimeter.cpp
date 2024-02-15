class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = -1, partSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < partSum) {
                ans = partSum + nums[i];
            }
            partSum += nums[i];
        }    
        return ans;  
    }
};