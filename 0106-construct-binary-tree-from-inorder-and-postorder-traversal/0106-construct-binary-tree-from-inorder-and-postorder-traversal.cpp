class Solution {
public:
    
    TreeNode* solve(vector<int> &in,vector<int> &p,int i,int j){
        if(i>j) return nullptr;
        
        TreeNode *temp = new TreeNode(p.back());
        int mid=0;
        
        while(mid<in.size() && in[mid]!=p.back()) mid++;
        p.pop_back();
        
        temp->right = solve(in,p,mid+1,j);
        temp->left = solve(in,p,i,mid-1);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        
        return solve(in,post,0,in.size()-1);
        
        // return root;
        
    }
};