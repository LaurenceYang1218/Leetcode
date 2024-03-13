class Solution {
public:
    int pivotInteger(int n) {
        int allSum = n * (n+1) / 2;
        for (int i = 1; i <= n; i++) {
            int prefixSum = i * (i + 1) / 2;
            int suffix = allSum - prefixSum + i;
            if (prefixSum == suffix) {
                return i;
            }
        }
        return -1;
    }
};