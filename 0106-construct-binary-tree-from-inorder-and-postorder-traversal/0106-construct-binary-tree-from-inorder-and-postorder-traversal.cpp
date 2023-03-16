int ss[6666];
class Solution {
public:
    
    TreeNode* solve(vector<int> &p,int i,int j){
        if(i>j) return nullptr;
        
        TreeNode *temp = new TreeNode(p.back());
        int mid=ss[p.back()+3000];
        p.pop_back();
        
        // while(mid<in.size() && in[mid]!=p.back()) mid++;
        // p.pop_back();
        
        temp->right = solve(p,mid+1,j);
        temp->left = solve(p,i,mid-1);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++) ss[in[i]+3000] = i;
        // memset(ss,-1,sizeof(ss));
        return solve(post,0,in.size()-1);
        
        // return root;
        
    }
};