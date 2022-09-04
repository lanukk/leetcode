/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val < root->val && q->val > root->val)
            return root;
        
        if(root == p || root == q)
            return root;
        
        if(p->val < root->val && q ->val < root->val)
            return helper(root->left, p, q);
        
        if(p->val > root->val && q->val > root->val)
            return helper(root->right, p, q);
        
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(q->val < p->val)
            swap(p, q);
        
        return helper(root, p, q);
    }
};