class Solution {
public:
    void dfs(int x, int y, int m, int n, vector<vector<int>>& grid, char dir) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2 || grid[x][y] == 3) {
            return;
        }
        grid[x][y] = 1;
        if (dir == 'U')
            dfs(x, y-1, m, n, grid, 'U');
        if (dir == 'D')
            dfs(x, y+1, m, n, grid, 'D');
        if (dir == 'L')
            dfs(x-1, y, m, n, grid, 'L');
        if (dir == 'R')
            dfs(x+1, y, m, n, grid, 'R');
                        
        return;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grids(m, vector<int>(n, 0));
        int gsz = guards.size(), wsz = walls.size();
        for (int i = 0; i < gsz; i++) {
            int x = guards[i][0], y = guards[i][1];
            grids[x][y] = 2;
        }
        for (int i = 0; i < wsz; i++) {
            int x = walls[i][0], y = walls[i][1];
            grids[x][y] = 3;
        }
        for (int i = 0; i < gsz; i++) {
            int x = guards[i][0], y = guards[i][1]; 
            dfs(x, y-1, m, n, grids, 'U');  
            dfs(x, y+1, m, n, grids, 'D');
            dfs(x-1, y, m, n, grids, 'L');
            dfs(x+1, y, m, n, grids, 'R');
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grids[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};