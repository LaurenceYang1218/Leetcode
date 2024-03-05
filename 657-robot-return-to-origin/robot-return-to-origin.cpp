class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> dirMap = {
            {'U', {0, -1}}, {'D', {0, 1}},
            {'L', {-1, 0}}, {'R', {1, 0}}
        };
        int x = 0, y = 0;
        for (int i = 0; i < moves.length(); i++) {
            x += dirMap[moves[i]].first;
            y += dirMap[moves[i]].second;
        }
        return ((x == 0) && (y == 0));
    }
};