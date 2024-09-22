class TrieNode {
public:
    TrieNode* childs[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            childs[i] = NULL;
        }
        isEnd = false;
    }

    bool contains(char ch) {
        return (childs[ch - 'a'] != NULL);
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
        for (char ch : str) {
            if (curr->childs[ch-'a'] == NULL) {
                curr->childs[ch-'a'] = new TrieNode();
            }
            curr = curr->childs[ch-'a'];
        }
        curr->isEnd = true;
        return;
    }

    bool hasPrefix(string str) {
        TrieNode* curr = root;
        for (char ch : str) {
            curr = curr->childs[ch - 'a'];
            if (curr == nullptr || !curr->isEnd) {
                return false;
            } 
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie tr;
        for (string str : words) {
            tr.insert(str);
        }
        string ret = "";
        for (string word : words) {
            if (tr.hasPrefix(word) && (word.length() > ret.length() || 
                    (word.length() == ret.length() && word < ret))) {
                    ret = word;
            }
        }
        return ret;
    }
};