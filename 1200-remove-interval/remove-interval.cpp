class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int start, end;
            if (intervals[i][0] < toBeRemoved[0]) {
                start = intervals[i][0];
                end = min(intervals[i][1], toBeRemoved[0]);
                ans.push_back({start, end});
            }
            if (intervals[i][1] > toBeRemoved[1]) {
                start = max(intervals[i][0], toBeRemoved[1]);
                end = intervals[i][1];
                ans.push_back({start, end});
            }
        }
        return ans;
    }
};