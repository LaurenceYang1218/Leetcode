class Solution {
public:
    vector<string> getPathFromRoot(string region, unordered_map<string, string>& treeMap) {
        vector<string> ret;
        string str = region;
        ret.push_back(str);
        while (treeMap.find(str) != treeMap.end()) {
            str = treeMap[str];
            ret.push_back(str);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> treeMap;
        for (size_t i = 0; i < regions.size(); i++) {
            string parent = regions[i][0];
            for (size_t j = 1; j < regions[i].size(); j++) {
                string child = regions[i][j];
                treeMap[child] = parent;
            }
        }
        vector<string> path1 = getPathFromRoot(region1, treeMap);
        vector<string> path2 = getPathFromRoot(region2, treeMap);
        int idx = 0, jdx = 0;
        string ans = "";
        while (idx < path1.size() && jdx < path2.size() && path1[idx] == path2[jdx]) {
            ans = path1[idx];
            idx++; 
            jdx++;
        }
        return ans;
    }
};