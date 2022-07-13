class TrieNode{
    public:
    map<char, TrieNode*> next;
    bool is_word;
    
    TrieNode(){
        is_word = false;
    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        
        for(char c : word){
            if(temp->next.find(c) == temp->next.end()){
                temp->next[c] = new TrieNode;
            }
            temp = temp->next[c];
        }
        temp->is_word = true;        
    }
    
    bool search(string word) {
        TrieNode *temp = root;
        for(char c : word){
            if(temp->next.find(c) == temp->next.end()){
                return false;
            }
            temp = temp->next[c];
        }
        return temp->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(char c : prefix){
            if(temp ->next.find(c) == temp->next.end()){
                return false;
            }
            temp = temp->next[c];
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