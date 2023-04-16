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
    
     pair<int,int> solve(TreeNode *root){
         if(!root) return {0,0};
            int temp = root->val;
            int t2 = 0;
            
          
            auto x = solve(root->left);
            auto y = solve(root->right);
            temp+=x.second;
            temp+=y.second;
            t2+=max(x.first,x.second);
            t2+=max(y.first,y.second);
        
         return {temp,t2};
    }
    
    int rob(TreeNode* root) {
        auto x = solve(root);
        return max(x.first,x.second);
    }
};