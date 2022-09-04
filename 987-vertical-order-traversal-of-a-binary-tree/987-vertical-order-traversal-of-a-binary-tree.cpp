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
    static bool cmp(const pair<int,int> &a,const pair<int,int> &b){
        if(a.second==b.second) return a.first<b.first;
        
        return a.second<b.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            queue<pair<TreeNode *,pair<int,int>>> dis;
            map<int,map<int,multiset<int>>> ck;
            
        dis.push({root,{0,0}});
        vector<vector<int>> ans;
        
        
        while(dis.size()){
            auto top=dis.front();
            dis.pop();
            int x=top.second.first;
            int y=top.second.second;
            ck[x][y].insert(top.first->val);
            
            if(top.first->left!=NULL) dis.push({top.first->left,{top.second.first-1,top.second.second+1}});
            if(top.first->right!=NULL) dis.push({top.first->right,{top.second.first+1,top.second.second+1}});
            
        }
        for(auto &k:ck){
            // sort(k.second.begin(),k.second.end(),cmp);
            vector<int> temp;
            for(auto &level:k.second){
                for(auto &vv:level.second)
                    temp.push_back(vv);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};