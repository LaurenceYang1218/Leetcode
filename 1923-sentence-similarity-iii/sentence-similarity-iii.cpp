class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> words1, words2;
        string word;
        while (ss1 >> word) {
            words1.push_back(word);
        }
        while (ss2 >> word) {
            words2.push_back(word);
        }
        if (words1.size() > words2.size()) {
            return areSentencesSimilar(sentence2, sentence1);
        }
        int start = 0, end1 = words1.size()-1, end2 = words2.size()-1;
        while (start <= end1 && words1[start] == words2[start]) {
            ++start;
        }
        while (end1 >= 0 && words1[end1] == words2[end2]) {
            --end1;
            --end2;
        }
        return end1 < start;  
    }
};