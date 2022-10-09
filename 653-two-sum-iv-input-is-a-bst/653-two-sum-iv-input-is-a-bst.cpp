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
int fq[55555];
int const N = 1e4;
class Solution {
public:
    Solution(){
        memset(fq,0,sizeof(fq));
    }
    // unordered_map<int,int> fq;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return 0;
        int val = k-root->val + N;
        if(fq[val]) return 1;
        fq[root->val+N]++;
        return findTarget(root->left,k)|findTarget(root->right,k);
    }
};