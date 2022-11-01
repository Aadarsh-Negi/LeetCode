class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &gg){
        if(i==gg.size()) return j;
        int j2 = j + gg[i][j];
        if(j2<0 || j2>=gg[0].size() || gg[i][j]!=gg[i][j2])
            return -1;
        
        return solve(i+1,j2,gg);
    }
    vector<int> findBall(vector<vector<int>>& gg) {
        int n = gg.size();
        int m = gg[0].size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            ans[i] = solve(0,i,gg);
        }
            
        
        return ans;
    }
};