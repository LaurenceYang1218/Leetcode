class TrieNode {
public:
    TrieNode* child[26];
    int isWord;
    int count;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            this->child[i] = NULL;
        }
        this->isWord = 0;
        this->count = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->child[word[i]-'a'] == NULL) {
                curr->child[word[i]-'a'] = new TrieNode();
            }
            curr = curr->child[word[i]-'a'];
            curr->count++;
        }
        curr->isWord++;
        return;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->child[word[i]-'a'] != NULL)
                curr = curr->child[word[i]-'a'];
            else
                return 0;
        }
        return curr->isWord;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (curr->child[prefix[i]-'a'] != NULL)
                curr = curr->child[prefix[i]-'a'];
            else
                return 0;
        }
        return curr->count;
    }
    
    void erase(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (curr->child[word[i]-'a'] != NULL) 
                curr = curr->child[word[i]-'a'];
            curr->count--;
        }
        curr->isWord--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */