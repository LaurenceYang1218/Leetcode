class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (auto it : nums) {
            frequency[it]++;
        }
        vector<pair<int, int>> freqVec(frequency.begin(), frequency.end());
  
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.second < p2.second) {
                return true;
            } else if (p1.second == p2.second) {
                return p1.first > p2.first;
            } else {
                return false;
            }
        });

        vector<int> res;
        for (auto it : freqVec) {
            for (int cnt = 0; cnt < it.second; cnt++) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};