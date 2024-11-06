class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        unordered_map<int, int> inDegrees;
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < numCourses; i++) {
            inDegrees[i] = 0;
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            int src = prerequisites[i][1], dst = prerequisites[i][0];
            graph[src].push_back(dst);
            inDegrees[dst]++;
        }
        queue<int> sources;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                sources.push(i);
            }
        }
        while (!sources.empty()) {
            int curr = sources.front();
            sources.pop();
            ret.push_back(curr);
            for (int i = 0; i < graph[curr].size(); i++) {
                inDegrees[graph[curr][i]]--;
                if (inDegrees[graph[curr][i]] == 0) {
                    sources.push(graph[curr][i]);
                }
            }
        }
        if (ret.size() == numCourses) {
            return ret;
        }else {
            return {};
        }
    }
};