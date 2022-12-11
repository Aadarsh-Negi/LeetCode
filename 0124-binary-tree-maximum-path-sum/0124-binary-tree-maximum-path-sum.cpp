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
    // int cnt=0;
    // void sz(TreeNode* root){
    //     if(root==NULL) return;
    //     sz(root->left);
    //     cnt++;
    //     sz(root->right);
    //     // return s1+s2;
    // }
    int ans=INT_MIN;
    int solve(TreeNode* root){
    if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        // cout<<l<<" "<<r<<"\n";
         ans=max({ans,root->val,root->val + max(l,r),root->val+l+r});
        return max(root->val + max(l,r),root->val);
        
    }
//     void solve2(TreeNode *root){
//         int l=(root->left==NULL?INT_MIN:root->left->val);
//         if(l==INT_MIN)
//             l=root->right->val;
        
//         ans=max({root->val,root->val+l,l});
//     }
    int maxPathSum(TreeNode* root) {
        // sz(root);
        // if(cnt==2){
        //     solve2(root);
        //     return ans;
        // }
          solve(root);
        return ans;
        
    }
};