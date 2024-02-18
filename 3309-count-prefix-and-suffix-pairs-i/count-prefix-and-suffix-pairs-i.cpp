class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (words[i].length() > words[j].length()) {
                    continue;
                }            
                if (words[j].compare(0, words[i].length(), words[i]) == 0
                    && words[j].compare(words[j].length()-words[i].length(), words[j].length(), words[i]) == 0) {
                    ans++;
                }
            } 
        }
        return ans;
    }
};