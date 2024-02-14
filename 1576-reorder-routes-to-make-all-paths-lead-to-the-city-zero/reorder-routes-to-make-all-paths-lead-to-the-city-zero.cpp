class Solution {
public:
    int cnt = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adjMatrix) {
        vector<pair<int, int>> neighbors = adjMatrix[node];
        for (auto it = neighbors.begin(); it != neighbors.end(); it++) {
            if (it->first != parent) {
                cnt += it->second;
                dfs(it->first, node, adjMatrix);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjMatrix(n);
        for (int i = 0; i < connections.size(); i++) {
            adjMatrix[connections[i][0]].push_back({connections[i][1], 1});
            adjMatrix[connections[i][1]].push_back({connections[i][0], 0});
        }
        dfs(0, -1, adjMatrix);
        return cnt;
    }
};