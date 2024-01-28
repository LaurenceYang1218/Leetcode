class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans;
        long long nEven = n / 2, nOdd = (n / 2) + n % 2;
        long long mEven = m / 2, mOdd = (m / 2) + m % 2;
        ans = nEven * mOdd + nOdd * mEven;
        return ans;
    }
};