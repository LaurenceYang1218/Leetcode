class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < heights.size()-1; i++) {
            int diff = heights[i+1] - heights[i];
            if (diff <= 0) {
                continue;
            }
            pq.push(diff);
            bricks -= diff;
            if (bricks < 0 && ladders == 0) {
                return i;
            }
            if (bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
        }
        return heights.size()-1;
    }
};