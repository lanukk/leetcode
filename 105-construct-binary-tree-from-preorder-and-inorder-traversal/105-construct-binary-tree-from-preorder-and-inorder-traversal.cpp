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
class Solution {
public:
    
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int leftSubtreeSize = mp[root->val];
        
        root->left = constructTree(preorder, preStart + 1, preStart + (leftSubtreeSize - inStart), inorder, inStart, leftSubtreeSize - 1, mp);
        
        root->right = constructTree(preorder, preStart + (leftSubtreeSize - inStart) + 1, preEnd, inorder, leftSubtreeSize + 1, inEnd, mp);     
        return root;        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = (int)preorder.size();
        int preStart = 0, inStart = 0, preEnd = n - 1, inEnd = n - 1;
        
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        
        TreeNode* root = constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
        return root;
    }
};