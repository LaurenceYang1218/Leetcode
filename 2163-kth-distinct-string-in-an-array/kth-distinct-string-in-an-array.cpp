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
        vector<int> arrIdx;
        for (auto it : cntMap) {
            if (it.second == 1) {
                arrIdx.push_back((find(arr.begin(), arr.end(), it.first)-arr.begin()));
            }
        }
        sort(arrIdx.begin(), arrIdx.end());
        if (k-1 >= arrIdx.size())
            return "";
        return arr[arrIdx[k-1]];
    }
};