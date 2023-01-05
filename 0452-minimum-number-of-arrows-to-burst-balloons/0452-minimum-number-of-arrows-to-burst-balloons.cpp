class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int ans=1;
        sort(p.begin(),p.end());
        int a=p[0][0];
        int b=p[0][1];
        for(auto &it:p){
            if(b>=it[0]){
                a = max(a,it[0]);
                b = min(b,it[1]);
            }else{
                a = it[0];
                b = it[1];
                ans++;
            }
        }
        return ans;
    }
};