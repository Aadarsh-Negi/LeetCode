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
        
        function<void(TreeNode *,int)> dfs = [&](TreeNode *cur,int lvl){
            if(!cur) return;
            if(lvl+1==depth){
                TreeNode *temp = cur->left;
                cur->left = new TreeNode(val);
                cur->left->left = temp;
                
                temp = cur->right;
                cur->right = new TreeNode(val);
                cur->right->right = temp;
                return;
                
            }
            dfs(cur->left,lvl+1);
            dfs(cur->right,lvl+1);
            
        };
        
        dfs(root,1);
        return root;
    }
};