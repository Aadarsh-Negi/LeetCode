class Solution {
public:
   
    vector<int> findBall(vector<vector<int>>& gg){
        vector<int> ans;
        function<int(int,int)> solve = [&](int i,int j){
            if(i==gg.size()) return j;
            int j2 = j + gg[i][j];
            if(j2<0 || j2>=gg[0].size() || gg[i][j]!=gg[i][j2])
                return -1;
            return solve(i+1,j2);
        };
    
        for(int i=0;i<gg[0].size();i++)
            ans.push_back(solve(0,i));
        return ans;
    }
};