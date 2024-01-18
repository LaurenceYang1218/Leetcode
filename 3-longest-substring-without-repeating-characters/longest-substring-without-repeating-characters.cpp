class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256, 0);
        int l = 0, ans = 0;
        for (int r = 0; r < s.length(); r++) {
            vec[s[r]]++;
            while (vec[s[r]] > 1) {
                vec[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};