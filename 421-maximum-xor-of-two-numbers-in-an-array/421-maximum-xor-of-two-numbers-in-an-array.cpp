class TrieNode{
    public:
        map<bool, TrieNode*> next;
};

class Trie{
    TrieNode* root;
    public:
        Trie(){
            root = new TrieNode;
        }
        
        void insert(int n){
            TrieNode * temp = root;
            
            for(int i = 31; i >= 0; i--){
                int status = (n & (1 << i));
                status = (status > 0) ? 1 : 0;
                
                if(temp->next.find(status) == temp->next.end()){
                    temp->next[status] = new TrieNode;
                }
                temp = temp->next[status];
            }
        }
        
        int maxXor(int n){
            int ans = 0;
            TrieNode*temp = root;
            
            for(int i = 31; i >= 0; i--){
                int status = (n & (1 << i));
                status = (status > 0) ? 1 : 0;
                
                if(temp->next.find(!status) == temp->next.end()){
                    temp = temp->next[status];
                } else {
                    ans = (ans | (1 << i));
                    temp = temp->next[!status];
                }
            }
            return ans;
        }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        for(int i : nums)
            obj.insert(i);
        
        int ans = 0;
        for(int i : nums)
            ans = max(ans, obj.maxXor(i));
        return ans;
    }
};