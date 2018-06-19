//Problem : Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.


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
    
    int height(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        return 1 + max(height(root->left), height(root->right));
        
    }
    
    int util(TreeNode* root, vector<vector<int>> &ret) {
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right == NULL) {
            ret[0].push_back(root->val);
            return 0;
        }
        
        int curr = 1+ max(util(root->left,ret),util(root->right,ret));
        
        ret[curr].push_back(root->val);
        
        return curr;
        
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        int ht = height(root);
        
        vector<vector<int>> ret(ht);
        int val = util(root, ret);
        
        return ret;
        
    }
};
