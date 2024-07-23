class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (auto it : nums) {
            freqMap[it]++;
        }
        vector<pair<int, int>> freqList(freqMap.begin(), freqMap.end());
        sort(freqList.begin(), freqList.end(), [](pair<int, int>& p1, pair<int, int>& p2){
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            }else {
                return p1.first > p2.first;
            }
        });
        vector<int> res;
        for (auto [num, count] : freqList) {
            for (int i = 0; i < count; i++) {
                res.push_back(num);
            }
        }
        return res;
    }
};