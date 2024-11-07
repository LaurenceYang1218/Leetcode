class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCnt(32, 0);
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < candidates.size(); j++) {
                int num = candidates[j];
                if ((num & (1 << i)) != 0) {
                    bitCnt[i]++;
                }
            }
        }
        return *max_element(bitCnt.begin(), bitCnt.end());
    }
};