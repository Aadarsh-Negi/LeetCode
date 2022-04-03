class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        
        int win[100005];
        int loss[100005];
        memset(win,0,sizeof(win));
        memset(loss,0,sizeof(loss));
        
        
        for(auto it:mat){
            win[it[0]]++;
            loss[it[1]]++;
        }
        vector<vector<int>> ans(2);
        
        for(int i=1;i<=100000;i++){
            if(win[i] || loss[i]){
                if(loss[i]==0) ans[1].push_back(i);
                if(loss[i]==1) ans[0].push_back(i);
            }
        }
                 sort(ans[0].begin(),ans[0].end());
                 sort(ans[1].begin(),ans[1].end());
        swap(ans[0],ans[1]);
                 return ans;
        
    }
};