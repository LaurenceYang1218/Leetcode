class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str;
        str.resize(word1.length() + word2.length());
        int idx1 = 0, idx2 = 0, cnt = 0;
        while(idx1 < word1.length() && idx2 < word2.length()) {
            if (cnt % 2 == 0) {
                str[cnt++] = word1[idx1++]; 
            }else {
                str[cnt++] = word2[idx2++];
            }   
        }
        while (idx1 == word1.length() && idx2 < word2.length()) {
            str[cnt++] = word2[idx2++];
        }
        while (idx1 < word1.length() && idx2 == word2.length()) {
            str[cnt++] = word1[idx1++];
        }
        return str;
    }
};