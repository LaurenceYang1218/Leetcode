class Solution {
public:
    
    void filter(string& str) {
        string tmpstr;
        for (size_t idx = 0; idx < str.length(); idx++) {
            if (isalpha(str[idx])) {
                tmpstr += tolower(str[idx]);
            }
        }
        str = tmpstr;
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        stringstream ss(paragraph);
        unordered_map<string, int> freqMap;
        size_t prev = 0, pos;
        string str;
        while ((pos = paragraph.find_first_of(" !?,;.", prev)) != string::npos) {
            if (pos > prev) {
                str = paragraph.substr(prev, pos-prev);
                filter(str);
                freqMap[str]++;
            }
            prev = pos + 1;

        }
        if (prev < paragraph.length()) {
            str = paragraph.substr(prev, string::npos);
            filter(str);
            freqMap[str]++;
        }
        for (auto it : freqMap) {
            cout << it.first << " " << it.second << '\n';
        }
        vector<pair<string, int>> freqList(freqMap.begin(), freqMap.end());
        sort(freqList.begin(), freqList.end(), [](pair<string, int>& p1, pair<string, int>& p2){
            return p1.second > p2.second;
        });
        
        for (auto it : freqList) {
            if (find(banned.begin(), banned.end(), it.first) == banned.end()) {
                return it.first;
            }
        }
        return "";
    }
};