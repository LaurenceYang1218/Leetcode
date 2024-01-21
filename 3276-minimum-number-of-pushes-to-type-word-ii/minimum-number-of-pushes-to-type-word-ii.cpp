class Solution {
public:

    int minimumPushes(string word) {
        map<char, int> wordCnt;
        
        for (int i = 0; i < word.length(); i++) {
            wordCnt[word[i]]++;
        }
    
        vector<pair<char, int>> sortWordCnt {wordCnt.begin(), wordCnt.end()};
        sort(sortWordCnt.begin(), sortWordCnt.end(), [](pair<char, int> l, pair<char, int> r) {
            return l.second > r.second;
        });
        
        int ans = 0;
        if (sortWordCnt.size() <= 8) {
            for (int i = 0; i < sortWordCnt.size(); i++) {
                ans += sortWordCnt[i].second;
            } 
        }else if (sortWordCnt.size() <= 16) {
            for (int i = 0; i < 8; i++) {
                ans += sortWordCnt[i].second;
            }
            for (int i = 8; i < sortWordCnt.size(); i++) {
                ans += (sortWordCnt[i].second * 2);
            }
        }else if (sortWordCnt.size() <= 24) {
            for (int i = 0; i < 8; i++) {
                ans += sortWordCnt[i].second;
            }   
            for (int i = 8; i < 16; i++) {
                ans += (sortWordCnt[i].second * 2);
            }
            for (int i = 16; i < sortWordCnt.size(); i++) {
                ans += (sortWordCnt[i].second * 3);
            }
        }else {
            for (int i = 0; i < 8; i++) {
                ans += sortWordCnt[i].second;
            }   
            for (int i = 8; i < 16; i++) {
                ans += (sortWordCnt[i].second * 2);
            }
            for (int i = 16; i < 24; i++) {
                ans += (sortWordCnt[i].second * 3);
            }
            for (int i = 24; i < sortWordCnt.size(); i++) {
                ans += (sortWordCnt[i].second * 4);
            }
        }
        return ans;
    }
};