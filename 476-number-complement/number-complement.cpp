class Solution {
public:
    int findComplement(int num) {
        int cntBinary = 0;
        int tmpNum = num;
        while (tmpNum) {
            cntBinary++;
            tmpNum >>= 1;
        }
        cout << cntBinary << endl;
        unsigned int mask = (1ull << cntBinary) - 1;

        return mask - num;
    }
};