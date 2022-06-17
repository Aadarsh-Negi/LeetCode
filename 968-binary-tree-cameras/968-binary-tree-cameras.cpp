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
    map<string,int> dp;
    int solve(TreeNode *root,bool par = true,bool par_cam = false){
        if(!root) return 0;
        if(root->left==root->right) return (par_cam?0:1);
        
        string key = to_string(root->val) + "." + to_string(par) + "." + to_string(par_cam);
        // cout<<key<<"\n";
        if(dp.count(key)) return dp[key];
        
        int temp = INT_MAX/2;
        if(par_cam){
            temp = solve(root->left,1,0) +solve(root->right,1,0);;
            // temp += 
        }
         if(par){
            if(root->left==NULL || root->right==NULL)  temp = min(temp,solve(root->left, false, false) + solve(root->right, false, false));
            else
                temp = min({temp,solve(root->left, false, false) + solve(root->right, true, false),solve(root->left, true, false) + solve(root->right, false, false)});
        }
        temp=min(temp,1+solve(root->left,1,1)+solve(root->right,1,1));
        
        return dp[key] = temp;
    }
    int c;
    void dfs(TreeNode *root){if(!root) return; root->val = c++; dfs(root->left); dfs(root->right);}
    int minCameraCover(TreeNode* root) {
        c=0;
        dfs(root);
        return solve(root);
    }
};