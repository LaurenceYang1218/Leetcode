class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string, int> prefixMap;
        for (int i = 0; i < arr1.size(); i++) {
            string numStr1 = to_string(arr1[i]);
            for (int j = 1; j <= numStr1.length(); j++) {
                string prefixStr = numStr1.substr(0, j);
                prefixMap[prefixStr] = j;
            }
        }
        for (int i = 0; i < arr2.size(); i++) {
            string numStr2 = to_string(arr2[i]);
            for (int j = 1; j <= numStr2.length(); j++) {
                string prefixStr = numStr2.substr(0, j);
                if (prefixMap.find(prefixStr) != prefixMap.end()) {
                    ans = max(ans, prefixMap[prefixStr]);
                }
            }
        }
        return ans;
    }
};