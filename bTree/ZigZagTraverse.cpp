/**
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root) return vector<vector<int>> {};
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> ret;
        s1.push(root);
        
        while(!s1.empty()) {
         
            vector<int> _ret;
            vector<int> _ret2;
            
            while(!s1.empty()) {
      
                TreeNode* node = s1.top();s1.pop();
                if(node->left!= NULL) s2.push(node->left);
                if(node->right!= NULL) s2.push(node->right);

                _ret.push_back(node->val);
                
            }
            
            ret.push_back(_ret);
            
            if(s1.empty() && s2.empty()) break;
            
            while(!s2.empty()) {
  
                TreeNode* node2 = s2.top();s2.pop();
                if(node2->right!= NULL) s1.push(node2->right);
                if(node2->left!= NULL) s1.push(node2->left);

                _ret2.push_back(node2->val);
                
            }
            
            ret.push_back(_ret2);
            
        }
        
        
        return ret;
        
    }
};
