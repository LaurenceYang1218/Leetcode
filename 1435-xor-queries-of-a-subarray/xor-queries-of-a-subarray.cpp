class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            bitset<32> out(0);
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                bitset<32> in(arr[j]);
                out ^= in;
            }
            res.push_back(static_cast<int>(out.to_ullong()));
        }
        return res;
    }
};