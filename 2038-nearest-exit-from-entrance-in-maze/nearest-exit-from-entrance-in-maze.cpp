class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {  
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = maze.size(), cols = maze[0].size();
        int startRow = entrance[0], startCol = entrance[1];
        maze[startRow][startCol] = '+';

        queue<array<int, 3>> mazeQ;
        mazeQ.push({startRow, startCol, 0});
        while (!mazeQ.empty()) {
            array<int, 3> currEntrance = mazeQ.front();
            mazeQ.pop();
            for (int i = 0; i < dir.size(); i++) {
                int nextRow = currEntrance.at(0) + dir[i].first;
                int nextCol = currEntrance.at(1) + dir[i].second;
                int currLevel = currEntrance.at(2);
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && maze[nextRow][nextCol] == '.') {
                    if (nextRow == 0 || nextRow == rows-1 || nextCol == 0 || nextCol == cols-1) {
                        return currLevel + 1;
                    }
                    maze[nextRow][nextCol] = '+';
                    mazeQ.push({nextRow, nextCol, currLevel + 1});
                }
            }
        }       
        return -1;
    }
};