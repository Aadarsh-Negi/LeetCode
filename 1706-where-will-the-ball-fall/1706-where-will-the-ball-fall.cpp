class Solution {
public:
   
    vector<int> findBall(vector<vector<int>>& gg){
        vector<int> ans;
        function<int(int,int)> solve = [&](int i,int j){
            return i==gg.size() ? j : (j+gg[i][j]<0 || j+gg[i][j]>=gg[0].size() || gg[i][j]!=gg[i][j+gg[i][j]]) ? -1 : solve(i+1,j+gg[i][j]);
        };
    
        for(int i=0;i<gg[0].size();i++)
            ans.push_back(solve(0,i));
        return ans;
    }
};