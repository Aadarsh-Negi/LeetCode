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
    
    int findMin(TreeNode* root){
       if(!root->left)return root->val;
       return findMin(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

      if(!root)return NULL;

      if(root->val==key){
         
         if(!root->left && root->right) return root->right;
         if(root->left && !root->right) return root->left;
         if(!root->left && !root->right) return NULL;
         
         root->val=findMin(root->right);
         root->right=deleteNode(root->right,root->val);

         return root;
      }
       
    if(key>root->val)
    root->right=deleteNode(root->right,key);
    else
    root->left=deleteNode(root->left,key);
      
     return root;

    }
};