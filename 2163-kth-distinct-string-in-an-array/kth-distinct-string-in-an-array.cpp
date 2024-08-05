class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cntMap;
        for (size_t i = 0; i < arr.size(); i++) {
            if (cntMap.find(arr[i]) == cntMap.end()) {
                cntMap.insert({arr[i], 1});
            }else {
                cntMap[arr[i]]++;
            }
        }
        vector<string> distinctStrs;
        for (size_t i = 0; i < arr.size(); i++) {
            if (cntMap[arr[i]] == 1) {
                distinctStrs.push_back(arr[i]);
            }
        }
        if (k-1 >= distinctStrs.size()) {
            return "";
        }
        return distinctStrs[k-1];
    }   
};