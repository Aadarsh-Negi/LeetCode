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
    bool f;
    int solve(TreeNode *r){
        if(!r) return 0;
        
        int l = solve(r->left);
        int rx = solve(r->right);
        if(abs(l-rx) > 1) f = 0;
        return max(l,rx) + 1;
    }
    bool isBalanced(TreeNode* root) {
        f=1;
        solve(root);
        return f;
    }
};