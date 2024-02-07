class Solution {
public:
    string frequencySort(string s) {
        map<char, int> strMap;
        for (int i = 0; i < s.length(); i++) {
            strMap[s[i]]++;
        }
        vector<pair<char, int>> strVec{strMap.begin(), strMap.end()};
        sort(strVec.begin(), strVec.end(), [](pair<char, int> p1, pair<char, int> p2){
            return p1.second > p2.second;
        });
        string ans = "";
        for (int i = 0; i < strVec.size(); i++) {
            for (int j = 0; j < strVec[i].second; j++) {
                ans += strVec[i].first;
            }
        }
        return ans;
    }
};