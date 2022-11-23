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
    TreeNode* invertTree(TreeNode* root) {
        
        queue<TreeNode *> qq;
        qq.push(root);
        while(qq.size()){
            int sz = qq.size();
            while(sz--){
                TreeNode *r = qq.front(); qq.pop();
                if(!r) continue;
                swap(r->left,r->right);
                if(r->left) qq.push(r->left);
                if(r->right) qq.push(r->right);
                
            }
        }
        
        
        return root;
    }
};