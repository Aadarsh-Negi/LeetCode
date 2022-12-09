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
    int s;
    void dfs(TreeNode* root,int l, int r){
        if(!root)return;
        if(l<=root->val&&r>=root->val){
            s+=root->val;
        }
        dfs(root->left,l,r);
        dfs(root->right,l,r);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        s=0;
        dfs(root,low,high);
        return s;
    }
};