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
    void solve(TreeNode *root,int &ss){
        if(!root) return;
        solve(root->right,ss);
        
        ss+=root->val;
        root->val = ss;
        
        solve(root->left,ss);
    }
    TreeNode* convertBST(TreeNode* root) {
        int ss=0;
        solve(root,ss);
        return root;
    }
};