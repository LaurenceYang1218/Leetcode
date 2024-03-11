class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int neg = 2;
        if (dividend > 0) {
            neg--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            neg--;
            divisor = -divisor;
        }
        vector<int> doubles, exps;
        int exp = -1;
        while (divisor >= dividend) {
            doubles.push_back(divisor);
            exps.push_back(exp);
            if (divisor < (INT_MIN / 2))
                break;
            divisor *= 2;
            exp *= 2;
        }
        int quotient = 0;
        for (int i = doubles.size()-1; i >= 0; i--) {
            if (doubles[i] >= dividend) {
                quotient += exps[i];
                dividend -= doubles[i];
            }
        }
        if (neg != 1) {
            return -quotient;
        }
        return quotient;
    }
};