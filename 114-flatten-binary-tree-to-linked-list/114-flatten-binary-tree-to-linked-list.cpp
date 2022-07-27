class Solution {
public:
    
    void flatten(TreeNode* root) {
         if(nullptr == root)
            return;
        
        TreeNode *rt = root->right;
        
        flatten(root->left);        
        
        root->right = root->left; 
        
        root->left = nullptr;
        
        while(root->right) root = root->right;
        
        flatten(rt);        
        
        root->right = rt;
    }
};