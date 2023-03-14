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
int ans;
void solve(TreeNode *root,int x = 0){
    if(!root) return;
    x*=10;
    x+=root->val;
    if(root->left == root->right) ans+=x;

    solve(root->left,x);
    solve(root->right,x);
}
    int sumNumbers(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};