class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        map<vector<int>, int> rowMap; 
        for (int i = 0; i < grid.size(); i++) {
            rowMap[grid[i]]++;
        }
        for (int i = 0; i < grid.size(); i++) {
            vector<int> colVec;
            for (int j = 0; j < grid.size(); j++) {
                colVec.push_back(grid[j][i]);
            }
            if (rowMap.find(colVec) != rowMap.end()) {
                ans += rowMap[colVec];
            }
        }       
        return ans;
    }
};