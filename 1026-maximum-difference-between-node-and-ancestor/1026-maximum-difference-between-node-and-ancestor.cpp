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
    int ans;
public:
    Solution(){
        ans=-1;
    }
    void solve(TreeNode *root,int mx,int mn){
        if(!root) return;
        
        ans=max(ans,abs(mx-root->val));
        ans=max(ans,abs(mn-root->val));
        
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        
        solve(root->left,mx,mn);
        solve(root->right,mx,mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int m = root->val;
        solve(root->left,m,m); 
        solve(root->right,m,m);
        return ans;
    }
};