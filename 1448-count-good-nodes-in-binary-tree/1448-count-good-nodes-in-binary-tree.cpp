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
    int solve(TreeNode * root,int mx=INT_MIN){
        if(root==NULL) return 0;
        
        
        if(mx<=root->val) return 1+solve(root->left,root->val) + solve(root->right,root->val);
        else return solve(root->left,mx) + solve(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        return solve(root);
    }
};