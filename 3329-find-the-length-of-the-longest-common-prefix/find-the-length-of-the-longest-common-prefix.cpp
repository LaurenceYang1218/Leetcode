class TrieNode {
public:
    TrieNode* childs[10];
    TrieNode() {
        for (int i = 0; i < 10; i++) {
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
        for (char ch : str) {
            if (!curr->contains(ch)) {
                curr->childs[ch - '0'] = new TrieNode();
            }
            curr = curr->childs[ch - '0'];
        }
        return;
    }

    int commonPrefix(string str) {
        int ret = 0;
        TrieNode* curr = root;
        for (char ch : str) {
            curr = curr->childs[ch - '0'];
            if (curr == NULL) {
                return ret;
            }
            ret++;
        }
        return ret;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Trie tr;
        for (int i = 0; i < arr1.size(); i++) {
            string str = to_string(arr1[i]);
            tr.insert(str);
        }
        
        for (int i = 0; i < arr2.size(); i++) {
            string str = to_string(arr2[i]);
            ans = max(ans, tr.commonPrefix(str));
        }
        return ans;
    }
};