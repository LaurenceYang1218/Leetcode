class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int curIdx = st.top();
            visited[curIdx] = true;
            st.pop();
            for (int i = 0; i < rooms[curIdx].size(); i++) {
                if (!visited[rooms[curIdx][i]])
                    st.push(rooms[curIdx][i]);
            }
        }
        bool ans = true;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                ans = false;
            }
        }
        return ans;
    }
};