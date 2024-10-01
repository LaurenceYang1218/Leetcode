class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
            if (it->second == 1) {
                return it->first;
            }
        }
        return -1;
    }
};