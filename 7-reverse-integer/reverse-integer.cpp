class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int last = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX && last > 7)) {
                return 0;              
            }else if (ans < INT_MIN / 10 || (ans == INT_MIN && last < -8)) {
                return 0;
            }
            ans = ans * 10 + last;
        }
        return ans;
    }
};