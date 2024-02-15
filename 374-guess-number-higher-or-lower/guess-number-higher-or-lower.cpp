/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        unsigned int low = 1, high = n;
        unsigned int mid = (low + high) / 2;
        int ret;
        while ((ret = guess(mid)) != 0) {
            if (ret > 0) {
                low = mid+1;
            }else {
                high = mid;
            }
            mid = (low + high) / 2;
        }
        return mid;
    }
};