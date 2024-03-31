class Solution {
public:
    int subarrayAtMost(vector<int>& nums, int k) {
        map<int, int> freqMap;
        int left = 0, right = 0;
        int ans = 0;
        for (right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;
            while (freqMap.size() > k) {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            } 
            ans += (right - left + 1);
        }    
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayAtMost(nums, k) - subarrayAtMost(nums, k-1);
    }   
};