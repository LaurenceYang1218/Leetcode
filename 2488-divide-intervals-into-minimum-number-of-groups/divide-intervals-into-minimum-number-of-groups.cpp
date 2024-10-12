class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> newIntervals;
        for (int i = 0; i < intervals.size(); i++) {
            newIntervals.push_back({intervals[i][0], 1});
            newIntervals.push_back({intervals[i][1]+1, -1});
        }
        sort(newIntervals.begin(), newIntervals.end());
        int currCnt = 0, maxOverlap = 0;
        for (int i = 0; i < newIntervals.size(); i++) {
            currCnt += newIntervals[i].second;
            maxOverlap = max(maxOverlap, currCnt);
        }
        return maxOverlap;
    }
};