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
    int goodNodes(TreeNode * root,int mx=INT_MIN){
        if(root==NULL) return 0;
        
        
        if(mx<=root->val) return 1+goodNodes(root->left,root->val) + goodNodes(root->right,root->val);
        else return goodNodes(root->left,mx) + goodNodes(root->right,mx);
    }
};