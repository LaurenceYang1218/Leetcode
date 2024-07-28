class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int INF = 1e9+7;
        vector<vector<int>> distance(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }
        for (const auto& edge : edges) {
            int src = edge[0], dst = edge[1], weight = edge[2];
            distance[src][dst] = weight;
            distance[dst][src] = weight;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][j] > distance[i][k] + distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
        int res = -1, minReachable = n;
        for (int i = 0; i < n; i++) {
            int cntReachable = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) 
                    continue;
                if (distance[i][j] <= distanceThreshold) {
                    cntReachable++;
                }
            }
            if (cntReachable <= minReachable) {
                minReachable = cntReachable;
                res = i;
            }
        }
        return res;
    }
};