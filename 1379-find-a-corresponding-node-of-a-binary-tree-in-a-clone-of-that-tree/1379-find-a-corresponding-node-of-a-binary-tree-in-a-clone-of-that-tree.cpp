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
    TreeNode* solve(TreeNode* r2,TreeNode* r1,TreeNode* tar){
        if(!r2) return NULL;
        if(r2==tar) return r1;
        // TreeNode* l = 
        // if(l) return l;
        return (solve(r2->left,r1->left,tar)==NULL?solve(r2->right,r1->right,tar):solve(r2->left,r1->left,tar));
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target){
        return solve(original,cloned,target);
    }
};