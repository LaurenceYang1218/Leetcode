class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> dist(n, 0);
        
        if (x > y) 
            swap(x, y);
        
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                int d = min(abs(i-j), abs(i-x)+abs(j-y)+1);
                dist[d-1] += 2;
            }
        }
        
        return dist;      
    }
};