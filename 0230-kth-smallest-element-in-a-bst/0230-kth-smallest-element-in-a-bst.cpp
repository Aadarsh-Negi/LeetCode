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
    unordered_map<int,int> countLeft;
    int countLeftNodes(TreeNode *root){
        if(!root) return 0;
        int left = countLeftNodes(root->left);
        int right = countLeftNodes(root->right);
        countLeft[root->val] = left+1;
        return left+right+1;
    }
    int qry(TreeNode *root,int k){
        if(countLeft[root->val]==k) return root->val;
        if(countLeft[root->val]<k) return qry(root->right,k-countLeft[root->val]);
        return qry(root->left,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        countLeftNodes(root);
        return qry(root,k);
    }
};