class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ret;
        istringstream iss1(s1), iss2(s2);
        vector<string> word1, word2;
        string str;
        while (iss1 >> str) {
            word1.push_back(str);
        }
        while (iss2 >> str) {
            word2.push_back(str);
        }
        unordered_map<string, int> cntMap;
        for (auto it : word1) {
            cntMap[it]++;
        }
        for (auto it : word2) {
            cntMap[it]++;
        }
        for (auto it : cntMap) {
            if (it.second == 1) {
                ret.push_back(it.first);
            }
        }
        return ret;
    }
};