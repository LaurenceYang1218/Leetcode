class Solution {
public:
    bool isPalindrome(string str) {
        int strLen = str.length();
        int l = 0, r = strLen-1;
        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            if (isPalindrome(words[i])) {
                ans = words[i];
                break;
            }
        }
        return ans;
    }
};