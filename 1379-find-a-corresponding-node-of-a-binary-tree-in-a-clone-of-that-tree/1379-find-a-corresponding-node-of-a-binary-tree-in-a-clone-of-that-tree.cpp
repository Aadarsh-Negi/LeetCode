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
    TreeNode* getTargetCopy(TreeNode* r2, TreeNode* r1, TreeNode* tar){
         if(!r2) return NULL;
        if(r2==tar) return r1;
        return (getTargetCopy(r2->left,r1->left,tar)==NULL?getTargetCopy(r2->right,r1->right,tar):getTargetCopy(r2->left,r1->left,tar));
    }
};