
class Solution {
public:
    void Union(vector<int>& parent, vector<int>& rank, int n1, int n2) {
        int p1 = Find(parent, n1);
        int p2 = Find(parent, n2);
        if (p1 == p2) {
            return;
        }
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }else {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        return;
    }

    int Find(vector<int>& parent, int n1) {
        while (n1 != parent[n1]) {
            parent[n1] = parent[parent[n1]];
            n1 = parent[n1];
        }
        return n1;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<int> parent(n+1);
        vector<int> rank(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        int numEdges = 0, cost = 0;
        for (int i = 0; i < connections.size(); i++) {
            array<int, 3> edge({connections[i][0], connections[i][1], connections[i][2]});
            auto [src, dst, weight] = edge;
            if (Find(parent, src) == Find(parent, dst)) 
                continue;
            Union(parent, rank, src, dst);
            cost += weight;
            numEdges++;
        }

        if (numEdges != n-1) {
            return -1;
        }else {
            return cost;
        }
    }
};