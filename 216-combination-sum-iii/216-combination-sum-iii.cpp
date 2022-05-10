class Solution {
public:
    vector<vector<int>> ans;
    void solve(int k,int n,int val,vector<int> &temp){
        
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(n<=0 || k<=0) return;
        
        if(val>9) return ;
        
        temp.push_back(val);
        solve(k-1,n-val,val+1,temp);
        temp.pop_back();
        solve(k,n,val+1,temp);
        
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        solve(k,n,1,a);
        return ans;
    }
};