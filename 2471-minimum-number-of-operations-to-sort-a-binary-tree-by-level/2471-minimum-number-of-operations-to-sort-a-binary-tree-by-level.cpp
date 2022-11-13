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
int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int swaps=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i) continue;
	        else {
	            swaps++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return swaps;
	}
class Solution {
public:
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> qq;
        
        int ans = 0;
        qq.push(root);
        while(qq.size()){
            int sz = qq.size();
            vector<int> temp;
            while(sz--){
                TreeNode *c = qq.front(); qq.pop();
                if(c->left) temp.push_back(c->left->val),qq.push(c->left);
                if(c->right) temp.push_back(c->right->val),qq.push(c->right);
                
            }
            int n = temp.size();
            // cout<<n<<"\n";
            ans+=minSwaps(temp);
            
        }
        return ans;
        
    }
};