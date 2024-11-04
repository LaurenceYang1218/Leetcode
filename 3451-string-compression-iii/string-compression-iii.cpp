class Solution {
public:
    string compressedString(string word) {
        unordered_map<char, int> uMap;
        string ret;
        uMap[word[0]]++;
        for (int i = 1; i < word.length(); i++) {
            uMap[word[i]]++;
            if (uMap[word[i]] == 9) {
                ret += "9";
                ret += word[i];
                uMap[word[i]] = 0;
            }
            if (word[i] != word[i-1] && uMap[word[i-1]] != 0) {
                ret += (to_string(uMap[word[i-1]]) + word[i-1]);
                uMap[word[i-1]] = 0;
            }                
        }
        if (uMap[word[word.length()-1]] != 0)
            ret += (to_string(uMap[word[word.length()-1]]) + word[word.length()-1]);
        return ret;
    }
};