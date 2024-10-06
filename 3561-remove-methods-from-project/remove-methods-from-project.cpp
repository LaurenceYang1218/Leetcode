class Solution {
public:
    void dfs(int root, vector<vector<int>>& graph, set<int>& suspicious) {
        if (suspicious.count(root)) {
            return;
        }
        suspicious.insert(root);
        for (auto it : graph[root]) {
            dfs(it, graph, suspicious);
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<vector<int>> revGraph(n);
        for (int i = 0; i < invocations.size(); i++) {
            int src = invocations[i][0], dst = invocations[i][1];
            graph[src].push_back(dst);
            revGraph[dst].push_back(src);
        }
        set<int> suspicious;
        dfs(k, graph, suspicious);
        vector<int> ret;
        for (int i = 0; i < invocations.size(); i++) {
            int src = invocations[i][0], dst = invocations[i][1];
            if (!suspicious.count(src) && suspicious.count(dst)) {
                suspicious.clear();
                break;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!suspicious.count(i)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};