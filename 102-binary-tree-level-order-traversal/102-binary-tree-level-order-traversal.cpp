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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> qq;
        
            qq.push(root);
        
        while(qq.size()){
            int x = qq.size();
            vector<int> temp;
            while(x--){
                if(qq.front()){
                    int cur = qq.front()->val;
                    temp.push_back(cur);
                    qq.push(qq.front()->left);
                    qq.push(qq.front()->right);
                }
                qq.pop();
            }
            if(temp.size())
                ans.push_back(temp);
        }
        return ans;
    }
};