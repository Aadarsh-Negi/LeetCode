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
     map<TreeNode *,int> dp;
  int dfs(TreeNode *root){
      if(!root) return 0;
      if(dp.count(root)) return dp[root];
      int s1,s2;
      s1=s2=0;
      if(root->left) {
          s1 = dfs(root->left->left);
          s1+= dfs(root->left->right);
      }
      if(root->right){
          s1+= dfs(root->right->left);
          s1+= dfs(root->right->right);
      }
      
      s2 = dfs(root->right);
      s2 += dfs(root->left);
      
      return dp[root] = max(s1+root->val,s2);
  }
    int rob(TreeNode* root) {
         return dfs(root);
    }
};