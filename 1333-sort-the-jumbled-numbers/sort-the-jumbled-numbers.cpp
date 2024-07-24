class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> oldNewMap;
        for (size_t i = 0; i < nums.size(); i++) {
            int oldNum = nums[i], newNum = 0;
            string str = to_string(nums[i]);
            for (char ch : str) {
                int newDigit = mapping[(ch - '0')];
                newNum = 10 * newNum + newDigit;
            }
            oldNewMap.push_back({newNum, i});
        }
        sort(oldNewMap.begin(), oldNewMap.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.first != p2.first) {
                return p1.first < p2.first;
            }else {
                return p1.second < p2.second;
            }
        });
        vector<int> res;
        for (auto it : oldNewMap) {
           res.push_back(nums[it.second]);
        }
        return res;
    }
};