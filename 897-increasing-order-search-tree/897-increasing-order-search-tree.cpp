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
    TreeNode *ans;
    TreeNode *temp;
    void in(TreeNode *root){
        if(!root) return;
        in(root->left);
        root->left=NULL;
        ans->right = root;
        ans=ans->right;
        in(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        ans = new TreeNode(0);
        temp = ans;
        in(root);
        return temp->right;
     
    }
};