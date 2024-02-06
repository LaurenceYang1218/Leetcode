class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int i = 0; i < asteroids.size(); i++) {
            bool flag = true;
            while(!st.empty() && (st.top() > 0 && asteroids[i] < 0)) {
                if (abs(st.top()) < abs(asteroids[i])) {
                    st.pop();
                    continue;
                }else if (abs(st.top()) == abs(asteroids[i])) {
                    st.pop();
                }
                flag = false;
                break;
            }
            if (flag)
                st.push(asteroids[i]);
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};