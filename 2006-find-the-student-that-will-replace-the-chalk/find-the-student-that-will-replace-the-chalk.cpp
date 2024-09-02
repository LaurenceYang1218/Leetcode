class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned long long chalkTotal = 0;
        for (size_t i = 0; i < chalk.size(); i++) {
            chalkTotal += chalk[i];
        }
        while (k >= chalkTotal) {
            k -= chalkTotal;
        }

        int idx = 0;
        if (k <= 0) {
            return 0;
        }else {
            
            for (int i = 0; i < chalk.size(); i++) {
                if (k < chalk[i]) {
                    idx = i;
                    break;
                }
                k -= chalk[i];
            }
        }
 
        return idx;
    }
};