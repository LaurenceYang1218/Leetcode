class SparseVector {
public:
    unordered_map<int, int> indexMap;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                indexMap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int val = 0;
        for (auto it : indexMap) {
            auto mapIt = vec.indexMap.find(it.first);
            if (mapIt != vec.indexMap.end()) {
                val += it.second * mapIt->second;
            }
        }
        return val;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);