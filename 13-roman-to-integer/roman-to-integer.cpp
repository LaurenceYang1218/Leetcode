class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<string, int> numMap = {
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},
            {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, 
            {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}
        };
        int idx = 0;
        while (idx < s.length()) {
            if (idx < s.length()-1) {
                auto it = numMap.find(s.substr(idx, 2));
                if (it != numMap.end()) {
                    ans += it->second;
                    idx += 2;
                    continue;
                } 
            }
            auto it = numMap.find(s.substr(idx, 1));
            if (it != numMap.end()) {
                ans += it->second;
                idx++;
            }
        }
        return ans;
    }
};