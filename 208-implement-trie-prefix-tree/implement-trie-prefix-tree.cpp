class TrieNode {
public:
    TrieNode *child[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
            isEnd = false;
        }
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->child[word[i]-'a'] == nullptr) {
                curr->child[word[i]-'a'] = new TrieNode();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->isEnd = true;
        return;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->child[word[i]-'a'] != nullptr) {
                curr = curr->child[word[i]-'a'];
            }else {
                return false;
            }
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (curr->child[prefix[i]-'a'] != nullptr) {
                curr = curr->child[prefix[i]-'a'];
            }else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */