class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n+1, 0);
        vec[0] = 1, vec[1] = 1;
        for (int i = 2; i <= n; i++) {
            vec[i] = vec[i-1] + vec[i-2];
        }
        if (n == 1) 
            return 1;
        else 
            return vec[n];
    }
};