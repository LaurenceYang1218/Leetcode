class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (strMap.find(str) == strMap.end()) {
                strMap[str] = {strs[i]};
            }else {
                strMap[str].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for (auto it = strMap.begin(); it != strMap.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};