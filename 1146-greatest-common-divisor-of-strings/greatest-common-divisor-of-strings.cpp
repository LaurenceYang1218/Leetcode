class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans;
        if (str1 + str2 != str2 + str1) {
            ans = "";
        }else {
            int len = gcd(str1.length(), str2.length());
            ans = (str1.length() > str2.length()) ? str1.substr(0, len) : str2.substr(0, len);   
        }
        return ans;
    }
};