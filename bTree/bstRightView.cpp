/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *  LC 199 https://leetcode.com/problems/binary-tree-right-side-view/description/
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
    
    void right_util(TreeNode* root, vector<int> &ret, int level) {
        
        if(root == NULL) return;
        
        if(level > ret.size()) ret.push_back(root->val);

        right_util(root->right, ret,level+1);
        
        right_util(root->left,ret,level+1);
    }
    
    
    vector<int> rightSideView(TreeNode *root) {
        
        vector<int> ret;
        
        right_util(root,ret,1);
        return ret;
        
        
    }
    
};
