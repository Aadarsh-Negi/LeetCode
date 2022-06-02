class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& m2){
        int n = m2.size();
        int m = m2[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i] = m2[i][j];
            }                                       
        }             
        return ans;
    }
};

// 1 2
// 3 4
// 5 6