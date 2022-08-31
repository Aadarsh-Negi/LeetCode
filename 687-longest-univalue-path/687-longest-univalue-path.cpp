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
    int solve(TreeNode *root,int &ans){
        if(!root) return 0;
        auto left = solve(root->left,ans);
        auto right = solve(root->right,ans);
        int l,r;
        l=r=0;
        if(root->left && root->left->val == root->val) l+=left+1;
        if(root->right && root->right->val == root->val) r+=right+1;
        ans = max(ans,l+r);
        return max(l,r);
        
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};