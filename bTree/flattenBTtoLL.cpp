/**
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 * Given a binary tree, flatten it to a linked list in-place.
 *
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
    void flatten(TreeNode* root) {
        
        if(root == NULL || (root->left == NULL && root->right == NULL)) return; 
        
        stack<TreeNode*> st;
        TreeNode *p = root;
        
        while(!st.empty() || p != NULL) {
            
            if(p->right !=NULL) st.push(p->right);
           
            if(p->left != NULL) {
                
                p->right = p->left;
                p->left = NULL;
            }
            
            else if(!st.empty()) {
                p->right = st.top();
                st.pop();
            }
            
            p = p->right;
              
        }
        
        return;
    }
};
