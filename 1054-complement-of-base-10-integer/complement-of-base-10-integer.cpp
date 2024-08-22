class Solution {
public:
    int bitwiseComplement(int n) {
        unsigned long mask = 0;
        int tmp = n;
        if (n == 0) return 1;
        while (tmp) {
            mask = (mask << 1) | 1;
            tmp >>= 1;
        }
        return mask - n;
    }
};