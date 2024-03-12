class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> billCnt;
        bool ans = false;
        for (int i = 0; i < bills.size(); i++) {
            billCnt[bills[i]]++;
            if (bills[i] == 10) {
                if (billCnt[5] == 0) {
                    return false;
                }else {
                    billCnt[5]--;
                }
            }else if (bills[i] == 20) {
                if (billCnt[10] > 0 && billCnt[5] > 0) {
                    billCnt[10]--;
                    billCnt[5]--;
                }else if (billCnt[5] >= 3) {
                    billCnt[5] -= 3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};