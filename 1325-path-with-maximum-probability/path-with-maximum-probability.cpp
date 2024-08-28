class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (size_t i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back({v, succProb[i]});
            graph[v].push_back({u, succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        vector<double> dist(n, 0.0);
        dist[start_node] = 1.0;

        while (!pq.empty()) {
            pair<double, int> p = pq.top();
            double prob = p.first;
            int src = p.second;
            pq.pop();
            for (auto& nb : graph[src]) {
                int dst = nb.first;
                double prevProb = nb.second;
                if (dist[dst] < prevProb * dist[src]) {
                    dist[dst] = prevProb * dist[src];
                    pq.push({dist[dst], dst});
                }
            }
        }
        return dist[end_node] == 0 ? 0 : dist[end_node];

        return 0;
    }
};