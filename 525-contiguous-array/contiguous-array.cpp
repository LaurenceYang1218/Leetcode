class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLen = 0, cnt = 0;
        unordered_map<int, int> numMap;
        numMap.insert({0, -1});
        for (int i = 0; i < nums.size(); i++) {
            cnt += (nums[i] == 1) ? 1 : -1;
            if (numMap.find(cnt) != numMap.end()) {
                maxLen = max(maxLen, i - numMap.find(cnt)->second);
            }else {
                numMap[cnt] = i;
            }
        }
        return maxLen;
    }
};