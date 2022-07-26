/**
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
    TreeNode *ans=NULL;
    bool check(TreeNode *root,TreeNode *p,TreeNode *q){
        if(!root) return false;
        int l=check(root->left,p,q);
        int r=check(root->right,p,q);
        int c=(root==p || root==q);
        if(l+r+c >=2) ans=root;
        return (l+r+c>0);
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root,p,q);
        return ans;
    }
};