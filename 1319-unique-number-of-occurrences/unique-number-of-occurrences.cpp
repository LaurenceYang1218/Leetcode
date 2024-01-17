class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numMap;
        unordered_set<int> numSet;
        
        for (int i = 0; i < arr.size(); i++) {
            numMap[arr[i]]++;
        }
    
        for (auto it = numMap.begin(); it != numMap.end(); it++) {
            if (!numSet.insert(it->second).second) {
                return false;
            }
        }
        return true;
    }
};