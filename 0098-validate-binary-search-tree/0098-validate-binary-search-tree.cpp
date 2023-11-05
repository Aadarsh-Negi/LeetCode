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
    bool isValidBST(TreeNode* root, long long mx = 1e10 + 223,long long mn = -1e11){
        if(!root) return 1;
        
        if(root->val >= mx || root->val <= mn) return 0;
        
        return isValidBST(root->left,root->val,mn)&isValidBST(root->right,mx,root->val);
    }
};