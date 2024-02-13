class Solution {
public:
    bool isPalindrome(int x) {
        bool ans = true;
        string str = to_string(x);
        int l = 0, r = str.length()-1;
        while (l < r) {
            if (str[l] == str[r]) {
                l++;
                r--;
            }else {
                ans = false;
                break;
            }
        }
        return ans;
    }
};