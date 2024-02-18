class Solution {
public:
    unordered_map<int, int> freqMap;
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    void dfs(int row, int col, int currNum, vector<vector<int>> mat, vector<vector<bool>> visited, int currDir) {
        if (isPrime(currNum) && currNum > 10) {
            freqMap[currNum]++;
        }
        if (currDir == -1) {
            for (int i = 0; i < dirs.size(); i++) {
                int currRow = row + dirs[i][0], currCol = col + dirs[i][1];
                if (currRow >= 0 && currRow < mat.size() && currCol >= 0 && currCol < mat[0].size()) {
                    if (!visited[currRow][currCol]) {
                        visited[currRow][currCol] = true;
                        dfs(currRow, currCol, 10*currNum + mat[currRow][currCol], mat, visited, i);
                    }
                }
            }            
        }else {
            int currRow = row + dirs[currDir][0], currCol = col + dirs[currDir][1];
            if (currRow >= 0 && currRow < mat.size() && currCol >= 0 && currCol < mat[0].size()) {
                if (!visited[currRow][currCol]) {
                    visited[currRow][currCol] = true;
                    dfs(currRow, currCol, 10*currNum + mat[currRow][currCol], mat, visited, currDir);
                }                
            }
        }
    }
    
    bool isPrime(int num) {
        if (num == 0 || num == 1) {
            return false;
        }

        for (int i = 2; i <= num/2; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
                visited[i][j] = true;
                dfs(i, j, mat[i][j], mat, visited, -1);            
            }
        }
        vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), [&](pair<int, int> p1, pair<int, int> p2) {
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            }else {
                return p1.first > p2.first;
            }
            
        });
        if (freqVec.size() != 0) {
            return freqVec.begin()->first;
        }

        return -1;
    }
};