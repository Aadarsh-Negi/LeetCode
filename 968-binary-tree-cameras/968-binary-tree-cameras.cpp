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
    // 0 - cover
    // 1 - req
    // 2 - plc;
    int solve(TreeNode *root){
        if(!root) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(r==1 || l==1){
            ans++;
            return 2;
        }
        if(l==0 and r==0) return 1;
        if(l==2 or r==2) return 0;
        return 4;
        
        
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root)==1) ans++;
        return ans;
    }
};