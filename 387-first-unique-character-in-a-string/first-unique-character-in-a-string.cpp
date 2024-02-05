class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char, int> charMap;
        for (int i = 0; i < s.length(); i++) {
            charMap[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (charMap[s[i]] == 1) {
                ans = i;
                break;
            }
        }
        return ans;      
    }
};