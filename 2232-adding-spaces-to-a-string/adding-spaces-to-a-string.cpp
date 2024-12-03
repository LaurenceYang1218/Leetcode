class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int spaceCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (spaceCnt < spaces.size() && i == spaces[spaceCnt]) {
                res += ' ';
                spaceCnt++;
            }
            res += s[i];
        }
        return res;
    }
};