class Solution {
public:
    map<char, string> charMap = {
                {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> ans;
    void solve(string digits, string currStr, int currLen) {
        if (currLen >= digits.length()) {
            ans.push_back(currStr);
            return;
        }
        char charIdx = digits[currLen];
        string mapStr = charMap[charIdx];
        for (int i = 0; i < mapStr.length(); i++) {
            currStr.push_back(mapStr[i]);
            solve(digits, currStr, currLen + 1);
            currStr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return ans;
        }
        string currStr = "";
        solve(digits, currStr, 0);
        return ans;
    }
};