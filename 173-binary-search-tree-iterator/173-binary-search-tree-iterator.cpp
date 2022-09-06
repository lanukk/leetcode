/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode* root;
    stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    
    int next() {
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
        int ans = st.top()->val;
        root = st.top();
        st.pop();
        
        root = root->right;
        
        return ans;
    }
    
    bool hasNext() {
        if(root != NULL || st.size() > 0)return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */