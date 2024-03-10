class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num1Map, num2Map;
        for (int i = 0; i < nums1.size(); i++) {
            num1Map[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            num2Map[nums2[i]] = 1;
        }
        vector<int> ans;
        for (auto it = num1Map.begin(); it != num1Map.end(); it++) {
            if (num2Map.find(it->first) != num2Map.end()) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};