class Solution {
public:
    struct pos {
        int x;
        int y;
    };
    int minKnightMoves(int x, int y) {
        vector<vector<int>> dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        pos origin = {0, 0};
        queue<pos> q;
        q.push(origin);
        int cnt = 0;
        bool visited[605][605] = {false};
        visited[origin.x+302][origin.y+302] = true;

        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                pos curr = q.front();
                q.pop();
                if (curr.x == x && curr.y == y) {
                    return cnt;
                }
                for (int j = 0; j < dirs.size(); j++) {
                    pos newPos = {curr.x + dirs[j][0], curr.y + dirs[j][1]};
                    if (!visited[newPos.x+302][newPos.y+302]) {
                        q.push(newPos);
                        visited[newPos.x+302][newPos.y+302] = true;
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
};