class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        unordered_map<string, int> prefixMap;
        for (int i = 0; i < arr1.size(); i++) {
            string str1 = to_string(arr1[i]);
            for (int j = 1; j <= str1.length(); j++) {
                prefixMap[str1.substr(0, j)]++;
            }
        }
        
        for (int i = 0; i < arr2.size(); i++) {
            string str2 = to_string(arr2[i]);
            for (int j = 1; j <= str2.length(); j++) {
                if (prefixMap.find(str2.substr(0, j)) == prefixMap.end()) {
                    break;
                }
                ans = max(ans, j);
            }
        }
        return ans;
    }
};