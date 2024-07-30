class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 1; i < rating.size()-1; i++) {
            int leftSmall = 0, leftLarge = 0;
            int rightSmall = 0, rightLarge = 0;
            int cntLeft = 0;
            while (cntLeft < i) {
                if (rating[cntLeft] < rating[i]) {
                    leftSmall++;
                }else {
                    leftLarge++;
                }
                cntLeft++;
            }
            int cntRight = i+1;
            while (cntRight <= rating.size()-1) {
                if (rating[cntRight] > rating[i]) {
                    rightLarge++;
                }else {
                    rightSmall++;
                }
                cntRight++;
            }
            res += (leftSmall * rightLarge);
            res += (leftLarge * rightSmall);
        }
        return res;
    }
};