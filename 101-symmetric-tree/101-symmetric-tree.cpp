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
    bool check(TreeNode *f1,TreeNode *f2){
        if(!f1 && !f2) return 1;
        if(!f1 || !f2) return 0;
        if(f1->val!=f2->val) return 0;
        return check(f1->left,f2->right) && check(f1->right,f2->left);
    }
    bool isSymmetric(TreeNode* root) {
           return check(root,root); 
      
    }
};