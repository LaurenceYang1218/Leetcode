class Solution {
public:
    int mySqrt(int x) {
        long long n = 1;
        while (n * n <= x) {
            n++;
        }
        return n-1;
    }
};