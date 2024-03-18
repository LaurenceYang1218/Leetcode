class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin(), points.end(), [&](vector<int> p1, vector<int> p2){
            return p1[1] < p2[1];
        });
        int prevEnd = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];
            if (currStart > prevEnd) {
                ans++;
                prevEnd = currEnd;
            }
        }
        return ans;
    }
};