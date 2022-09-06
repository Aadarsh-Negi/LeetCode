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
    int solve(TreeNode *root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == 0) root->left = nullptr;
        if(right == 0 ) root->right = nullptr;
        
        return (left||right||root->val);
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root) ? root : nullptr;
    }
};