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
    void dfs(vector<int>&cnt,TreeNode *root){
        if(!root) {
            return;
        }
        cnt[root->val]++;
        if(root->left==root->right){
              
            int ok=0;
            
            for(int i=0;i<10;i++){
                if(cnt[i]&1) ok++;
            }
            if(ok<=1) ans++;
            cnt[root->val]--;
            return;
        }
        
        
        dfs(cnt,root->left);
        dfs(cnt,root->right);
        cnt[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        vector<int> cnt(10,0);
        dfs(cnt,root);
        
        return ans;
    }
};