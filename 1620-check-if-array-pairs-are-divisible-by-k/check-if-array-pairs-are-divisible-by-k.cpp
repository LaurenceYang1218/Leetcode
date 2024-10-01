class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for (auto it : arr) {
            um[(it % k + k) % k]++;
        }
        for (auto it : um) {
            if (it.first == 0) {
                if ((it.second % 2) != 0) {
                    return false;
                }
            }else {
                auto pairIt = um.find(k - it.first);
                if (pairIt == um.end() || pairIt->second != it.second)
                    return false;
            }
        }
        return true;
    }
};