class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, temp = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
                                || s[i] == 'o' || s[i] == 'u') {
                temp++;
            }
        }
        ans = temp;
        for (int i = k; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
                                || s[i] == 'o' || s[i] == 'u') {
                temp++;
            }
            if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i'
                                || s[i-k] == 'o' || s[i-k] == 'u') {
                temp--;
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};