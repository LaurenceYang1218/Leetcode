class TrieNode {
public: 
    TrieNode* child[26];
    unsigned int cnt;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        cnt = 0;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string str) {
        TrieNode* curr = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (curr->child[c-'a'] == nullptr) {
                curr->child[c-'a'] = new TrieNode();       
            }
           
            curr = curr->child[c-'a'];
            curr->cnt++;
        }
        return;
    }

    void remove(string str) {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (curr->child[c-'a'] != nullptr) {
                curr = curr->child[c-'a'];
                curr->cnt--;
            }
        }
        return;
    }
    
    bool search(string str) {
        TrieNode* curr = root;
        for (int i = 0; i < str.length(); i++) {
            if (curr->child[str[i]-'a'] == nullptr || curr->child[str[i]-'a']->cnt == 0) {
                return false;
            }
            curr = curr->child[str[i]-'a'];
        }
        return true;
    }
};

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans;
        Trie tr; 
        for (string str : arr) {
            for (int i = 0; i < str.length(); i++) {
                tr.insert(str.substr(i));
            }
        }
        for (string str : arr) {
            for (int i = 0; i < str.length(); i++) {
                tr.remove(str.substr(i));
            }
            
            string shortestSubstr;
            for (int len = 1; len <= str.length(); len++) {
                for (int pos = 0; pos < str.length()-len+1; pos++) {
                    string s = str.substr(pos, len);
                    if (!tr.search(s) && (shortestSubstr.empty() || (shortestSubstr.length() == s.length() && s < shortestSubstr))) {
                        shortestSubstr = s;
                    } 
                }
            }
            ans.push_back(shortestSubstr);
            for (int i = 0; i < str.length(); i++) {
                tr.insert(str.substr(i));
            }
        }

        return ans;
    }
};