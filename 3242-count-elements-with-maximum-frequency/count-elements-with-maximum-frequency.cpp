class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]]++;
        }
        int maxFreq = 0;
        for (auto it = numMap.begin(); it != numMap.end(); it++) {
            maxFreq = max(it->second, maxFreq);
        }
        int numFreq = 0;
        for (auto it = numMap.begin(); it != numMap.end(); it++) {
            if (it->second == maxFreq) {
                numFreq++;
            }
        }
        return numFreq * maxFreq;
    }
};