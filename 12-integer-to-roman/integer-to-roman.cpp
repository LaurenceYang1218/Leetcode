class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> numMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };  
        string ans = "";
        while (num != 0) {
            for (auto it = numMap.begin(); it != numMap.end(); it++) {
                if (num - it->first >= 0) {
                    num -= it->first;
                    ans += it->second;
                    break;
                }
            }
        }
        return ans;
    }
};