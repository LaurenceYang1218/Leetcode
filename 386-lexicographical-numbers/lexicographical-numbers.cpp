class TrieNode {
public:
    TrieNode* childs[10];
    TrieNode() {
        for (int i = 0; i <= 9; i++) {
            childs[i] = NULL;
        }
    }
    bool contains(char ch) {
        return (childs[ch - '0'] != NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string str) {
        TrieNode* curr = root;
        for (size_t i = 0; i < str.size(); i++) {
            if (!curr->contains(str[i])) {
                curr->childs[str[i]-'0'] = new TrieNode();
            }
            curr = curr->childs[str[i]-'0'];
        }
    }

    void traverse(vector<int>& vec, int curr, int n, TrieNode* node) {
        if (curr > n) {
            return;
        }
        if (curr != 0)
            vec.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            if (node->childs[i])
                traverse(vec, curr * 10 + i, n, node->childs[i]);
        }
        return;
    }

    void generateNum(vector<int>& vec, int n) {
        traverse(vec, 0, n, root);
        return;
    }
};


class Solution {
public:

    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        Trie tr;
        for (int i = 1; i <= n; i++) {
            tr.insert(to_string(i));
        }
        tr.generateNum(ret, n);
        return ret;
    }
};