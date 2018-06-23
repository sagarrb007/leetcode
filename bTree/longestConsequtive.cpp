/**
 * Given a binary tree, find the length of the longest consecutive sequence path.
 * The path refers to any sequence of nodes from some starting node to any node in
 * the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
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
    
    int util(TreeNode* root, int &len) {
        
        if(!root) return 0 ;
        if(!root->left && !root->right) {
            //len = 1;
            return 1;
        }
        
        int left = util(root->left,len);
        int right = util(root->right,len);

        if (root->left && root->val+1 == root->left->val) {
           
            left++;
        }
        else if (root->right && root->val+1 == root->right->val) {
         right++;
        }
        else return 1;
        len = max(len,max(left,right));
        //cout << left << right << root->val << len << endl;
        return max(left,right);
        
    }
    
    int longestConsecutive(TreeNode* root) {
        
        int len = 0; 
        int val = util(root,len);
        
        return max(val,len);
    }
