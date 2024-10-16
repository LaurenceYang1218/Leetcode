class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret = "";
        priority_queue<pair<int, char>> pq;
        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            int freq = p.first;
            char currChar = p.second;
            int currLen = ret.length();
            if (currLen >= 2 && ret[currLen-1] == currChar && ret[currLen-2] == currChar) {
                if (pq.empty())
                    break;
                pair<int, char> newP = pq.top();
                pq.pop();
                ret += newP.second;
                newP.first--;
                if (newP.first > 0)
                    pq.push(newP);
            }else {
                ret += currChar;
                freq--;
            }   
            if (freq > 0) {
                pq.push({freq, currChar});
            }
        }
        return ret;
    }
};