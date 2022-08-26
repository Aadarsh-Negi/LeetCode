class Solution {
public:
    void solve(vector<int> &can,int tar,int i,vector<vector<int>> &ans,vector<int> cur){
        if(tar==0){
            ans.push_back(cur);
            return;
        }
        if(tar<0 || i==can.size()) return;
        for(int k=i;k<can.size();k++){
                if(can[k]>tar) return; 
                if(k>i && can[k]==can[k-1]) continue;
                cur.push_back(can[k]);
                solve(can,tar-can[k],k+1,ans,cur);
                cur.pop_back();
         
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        
        vector<vector<int>> ans;
        sort(can.begin(),can.end());
                solve(can,tar,0,ans,{});        
        return ans;
        
    }
};