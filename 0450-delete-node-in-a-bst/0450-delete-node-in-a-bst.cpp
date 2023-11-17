class Solution {
public:
    
    void solve(TreeNode* root,vector<TreeNode*> &data){
        if(!root)return;
        solve(root->left,data);
        data.push_back(root);
        solve(root->right,data);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;

        vector<TreeNode*> data;
        solve(root,data);
        
        for(int i=0;i<data.size();i++){
        if(data[i]->val==key){
            data.erase(data.begin()+i);
            break;
         }
        }

        if(data.size()==0)return NULL;

        for(int i=0;i<data.size()-1;i++){
            data[i]->left=NULL;
            data[i]->right=data[i+1];
        }

        data[data.size()-1]->left=NULL;
        data[data.size()-1]->right=NULL;

        return data[0];
    }
};