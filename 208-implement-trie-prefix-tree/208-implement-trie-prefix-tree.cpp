class TrieNode{
public:
    TrieNode *next[26];
    bool isWord;
    
    TrieNode(){
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        isWord = false;
    }
};

class Trie {
    TrieNode *root = NULL;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        
        for(char c : word){
            if(temp -> next[c - 'a'] == NULL){
                temp -> next[c - 'a'] = new TrieNode();
            }
            temp = temp -> next[c - 'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(char c : word){
            if(temp->next[c - 'a'] == NULL)
                return false;
            temp = temp->next[c - 'a'];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode * temp = root;
        for(char c : prefix){
            if(temp->next[c - 'a'] == NULL)
                return false;
            temp = temp -> next[c - 'a'];
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