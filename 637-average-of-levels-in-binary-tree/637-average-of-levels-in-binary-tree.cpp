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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> qq;
        qq.push(root);
        while(qq.size()){
            int x = qq.size();
            long long res=0;
            for(int i=0;i<x;i++){
                res+=qq.front()->val;
                if(qq.front()->left) qq.push(qq.front()->left);
                if(qq.front()->right) qq.push(qq.front()->right);
                qq.pop();
            }
            double val = res*1.0;
            val/=1.0*x;
            ans.push_back(val);
        }
        
        
        return ans;
    }
};