class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int legalCnt = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            bool emptyLeft = (i == 0) || (flowerbed[i-1] == 0);
            bool emptyRight = (i == flowerbed.size()-1) || (flowerbed[i+1] == 0);
            if (flowerbed[i] == 0 && emptyLeft && emptyRight) {
                legalCnt++;
                flowerbed[i] = 1;
            }
        }
        return (legalCnt >= n);
    }
};