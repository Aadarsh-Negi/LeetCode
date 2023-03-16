int ss[6666];
int p[3333];
class Solution {
public:
    int k;
    TreeNode* solve(int i,int j){
        if(i>j) return nullptr;
        
        TreeNode *temp = new TreeNode(p[k]);
        int mid=ss[p[k]+3000];
        // p.pop_back();
        k--;
        
        temp->right = solve(mid+1,j);
        temp->left = solve(i,mid-1);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        for(int i=0;i<in.size();i++) ss[in[i]+3000] = i;
        for(int i=0;i<in.size();i++) p[i] = post[i];
        k = in.size()-1;
        return solve(0,in.size()-1);
    }
};