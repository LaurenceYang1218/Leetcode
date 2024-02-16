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

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
    bool searchNode(string word, int idx, TrieNode *node) {
        if (node == nullptr) {
            return false;
        }
        if (idx == word.size()) {
            return node->isEnd;
        }
        if (word[idx] != '.') {
            return searchNode(word, idx + 1, node->child[word[idx]-'a']);
        }            
        for (int i = 0; i < 26; i++) {
            if (searchNode(word, idx + 1, node->child[i])) {
                return true;
            }
        }
        return false;
    }   

    bool search(string word) {
        TrieNode *curr = root;
        return searchNode(word, 0, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */