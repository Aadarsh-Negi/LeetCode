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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>qq;
        if(root)
            qq.push(root);
        
        while(qq.size()){
            int x = qq.size();
            x--;
            while(x--){
                if(qq.front()->left)qq.push(qq.front()->left);
                if(qq.front()->right)qq.push(qq.front()->right);
                qq.pop();
            }
            ans.push_back(qq.front()->val);
            if(qq.front()->left)qq.push(qq.front()->left);
            if(qq.front()->right)qq.push(qq.front()->right);
            qq.pop();
        }
        return ans;
    }
};