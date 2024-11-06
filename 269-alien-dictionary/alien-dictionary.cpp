class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> inDegrees;
        unordered_map<char, vector<char>> graph;
        for (string word : words) {
            for (char ch : word) {
                inDegrees[ch] = 0;
                graph[ch] = vector<char>();
            } 
        }

        for(int i = 0; i < words.size()-1; i++) {
            string w1 = words[i], w2 = words[i+1];
            if (w1.length() > w2.length() && w1.substr(0, w2.length()) == w2) {
                return "";
            }
            int minLen = min(w1.length(), w2.length());
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    inDegrees[w2[j]]++;
                    break;
                }
            }
        } 

        queue<char> q;
        for (auto it : inDegrees) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }
        string ret;
        while (!q.empty()) {
            char ch = q.front();
            q.pop();
            ret += ch;
            for (int i = 0; i < graph[ch].size(); i++) {
                inDegrees[graph[ch][i]]--;
                if (inDegrees[graph[ch][i]] == 0) {
                    q.push(graph[ch][i]);
                }
            }
        }
        if (ret.length() < inDegrees.size()) {
            return "";
        }else {
            return ret;
        }
    } 
};