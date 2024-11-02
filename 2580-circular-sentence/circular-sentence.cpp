class Solution {
public:
    bool isCircularSentence(string sentence) {
        int len = sentence.length();
        vector<string> words;
        stringstream sstr(sentence);
        string str;
        while (sstr >> str) {
            words.push_back(str);
        }
        if (words.size() == 1) {
            return sentence[0] == sentence[len-1];
        }
        for (int i = 1; i < words.size(); i++) {
            int lastLen = words[i-1].length();
            if (words[i][0] != words[i-1][lastLen-1]) {
                return false;
            }
        }
        return sentence[0] == sentence[len-1];
    }
};