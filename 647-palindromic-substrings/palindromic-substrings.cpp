class Solution {
public:
    int checkPalindrome(string s, int low, int high) {
        int ret = 0;
        while (low >= 0 && high < s.length()) {
            if (s[low] != s[high]) 
                break;
            else {
                low--;
                high++;
                ret++;
            }
        }
        return ret;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += checkPalindrome(s, i, i);
            ans += checkPalindrome(s, i, i+1);
        }
        return ans;
    }
};