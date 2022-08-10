class Solution {
public:
    TreeNode *solve(vector<int> &ar,int i,int j){
        if(i>=j) return nullptr;
        int mid = (i+j)/2;
        TreeNode *rx = new TreeNode(ar[mid]);
        rx->left = solve(ar,i,mid);
        rx->right = solve(ar,mid+1,j);
        return rx;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size());
    }
};