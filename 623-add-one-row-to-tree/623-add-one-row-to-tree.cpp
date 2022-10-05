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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode *new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        
        auto dfs = [&](auto &&dfs,TreeNode *cur,int lvl,TreeNode *prev,int lf){
            
            if(lvl==depth){
                if(lf){
                    prev->left = new TreeNode(val);
                    prev->left->left = cur;
                }else{
                    prev->right = new TreeNode(val);
                    prev->right->right = cur;
                }
                return;
            }
            if(!cur) return;
            dfs(dfs,cur->left,lvl+1,cur,1);
            dfs(dfs,cur->right,lvl+1,cur,0);
            
        };
        
        dfs(dfs,root,1,nullptr,0);
        return root;
    }
};