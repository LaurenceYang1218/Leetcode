class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), [](int& a, int& b){
            return a > b;
        });
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < (i+1)) {
                return i;
            }
        }
        return citations.size();
    }
};