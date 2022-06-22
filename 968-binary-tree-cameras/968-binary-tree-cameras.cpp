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
    vector<int> done;
    int ans;
    void dfs(TreeNode *root,TreeNode *par){
        if(!root) return;
        dfs(root->left,root);
        dfs(root->right,root);
        
        // if(par==NULL){
            if((par==NULL && !done[root->val]) || (root->left && !done[root->left->val]) || (root->right && !done[root->right->val])){
                ans++;
                done[root->val]=1;
                if(par) done[par->val]=1;
                if(root->left) done[root->left->val]=1;
                if(root->right) done[root->right->val]=1;
            }
        // }
    }
    
    void valx(TreeNode *root,int &c){if(!root) return; root->val=c++; valx(root->left,c); valx(root->right,c);}
    int minCameraCover(TreeNode* root) {
        int v=0;
        ans=0;
        valx(root,v);
        done.resize(v+1,0);
        
        dfs(root,NULL);
        
        return ans;
        
    }
};