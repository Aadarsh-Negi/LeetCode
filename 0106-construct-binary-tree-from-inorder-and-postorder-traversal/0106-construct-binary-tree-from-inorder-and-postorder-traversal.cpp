class Solution {
public:
    unordered_map<int,int> ss;
    TreeNode* solve(vector<int> &p,int i,int j){
        if(i>j) return nullptr;
        
        TreeNode *temp = new TreeNode(p.back());
        int mid=ss[p.back()];
        p.pop_back();
        
        // while(mid<in.size() && in[mid]!=p.back()) mid++;
        // p.pop_back();
        
        temp->right = solve(p,mid+1,j);
        temp->left = solve(p,i,mid-1);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++) ss[in[i]] = i;
        
        return solve(post,0,in.size()-1);
        
        // return root;
        
    }
};