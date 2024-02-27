class Solution {
public:
    int diameter = 0;
    int dfs(int currNode, vector<bool>& visited, vector<vector<int>>& adjMatrix) {
        int top1Distance = 0, top2Distance = 0;
        visited[currNode] = true;
        vector<int> neighbors = adjMatrix[currNode];
        for (int i = 0; i < neighbors.size(); i++) {
            int distance = 0;
            if (!visited[neighbors[i]]) {
                distance = 1 + dfs(neighbors[i], visited, adjMatrix);
            }
            if (distance > top1Distance) {
                top2Distance = top1Distance;
                top1Distance = distance;
            }else if (distance > top2Distance) {
                top2Distance = distance;
            }
            diameter = max(diameter, top1Distance + top2Distance);
        }
        return top1Distance; 
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjMatrix(n);
        for (int i = 0; i < edges.size(); i++) {
            adjMatrix[edges[i][0]].push_back(edges[i][1]);
            adjMatrix[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        dfs(0, visited, adjMatrix);
        return diameter;
    }
};