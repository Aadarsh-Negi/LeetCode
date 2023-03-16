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
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        auto dfs = [&](auto &&dfs,TreeNode *r,int s){
            if(!r) return;
            temp.push_back(r->val);
            dfs(dfs,r->right,s-r->val);
            dfs(dfs,r->left,s-r->val);
            if(r->left == r->right && s-r->val==0) ans.push_back(temp);
            temp.pop_back();
        };
        dfs(dfs,root,tar);
        
        return ans;
    }
};