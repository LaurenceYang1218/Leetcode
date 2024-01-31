class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            int currTemp = temperatures[i];
            while (!st.empty() && temperatures[st.top()] < currTemp) {
                int prevIdx = st.top();
                answer[prevIdx] += (i - prevIdx);
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};