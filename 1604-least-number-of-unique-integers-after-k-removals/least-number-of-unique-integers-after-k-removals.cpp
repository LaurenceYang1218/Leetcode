class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> arrMap;
        for (int i = 0; i < arr.size(); i++) {
            arrMap[arr[i]]++;
        }
        vector<pair<int, int>> vec(arrMap.begin(), arrMap.end());
        sort(vec.begin(), vec.end(), [&](pair<int, int> p1, pair<int, int> p2) {
            return p1.second < p2.second;
        });
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (k >= vec[i].second) {
                k -= vec[i].second;
                cnt++;
            }else {
                break;
            }
        }
        return vec.size() - cnt;
    }
};