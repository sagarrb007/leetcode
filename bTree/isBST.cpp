/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * LC 98
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
    
    bool _helper(TreeNode* root, long lower, long upper) {
     
        if(root == NULL) return true;
        
        if(root->val <= lower || root->val >= upper) return false;
        
        return _helper(root->left,lower,root->val) &&
            _helper(root->right, root->val, upper);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        
        return _helper(root, LONG_MIN,LONG_MAX);
        
    }
};
