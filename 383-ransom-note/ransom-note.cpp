class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        int rMap[26] = {0}, mMap[26] = {0};
        for (int i = 0; i < ransomNote.length(); i++) {
            rMap[ransomNote[i]-'a']++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            mMap[magazine[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (rMap[i] > mMap[i]) {
                return false;
            }
        }
        return true;
    }
};