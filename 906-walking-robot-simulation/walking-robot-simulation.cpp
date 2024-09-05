class Solution {
public:
    const int HASH_VALUE = 60005;
    inline int createHashCoord(vector<int>& obstacle) {
        return obstacle[0] * HASH_VALUE + obstacle[1];
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstaclesHashSet;
        for (size_t i = 0; i < obstacles.size(); i++) {
            obstaclesHashSet.insert(createHashCoord(obstacles[i]));
        }
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIdx = 0;
        vector<int> currDir =  dirs[dirIdx];
        pair<int, int> p = {0, 0};
        int ret = 0;
        for (size_t i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                dirIdx = ((dirIdx + 1) % 4 + 4) % 4;
                currDir = dirs[dirIdx];
            }else if (commands[i] == -2) {
                dirIdx = ((dirIdx - 1) % 4 + 4) % 4;
                currDir = dirs[dirIdx];
            }else {
                for (int j = 0; j < commands[i]; j++) {
                    vector<int> nextP = {p.first + currDir[0], p.second + currDir[1]};
                    if (obstaclesHashSet.contains(createHashCoord(nextP))) {
                        break;
                    }
                    p.first += currDir[0];
                    p.second += currDir[1];
                }
                ret = max(ret, p.first * p.first + p.second * p.second);
            }
        }
        return ret;
    }
};