/**

Problem : Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
LC 113 https://leetcode.com/problems/path-sum-ii/description/


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
    
    void _pathSum(TreeNode* root,vector<vector<int>> & ret,vector<int> &aux ,int sum) {
        
        if(!root) return;
        if(sum - root->val < 0 && root->left ==NULL && root->right == NULL) return;
         aux.push_back(root->val);
        if(sum - root->val == 0 && root->left ==NULL && root->right == NULL) {
            ret.push_back(aux);
            aux.pop_back();
            return;
        }
        
        _pathSum(root->left,ret, aux, sum - root->val);
        _pathSum(root->right,ret, aux, sum - root->val);
        
        aux.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> aux;
        
        _pathSum(root,ret,aux,sum);
        
        return ret;
    }
};
