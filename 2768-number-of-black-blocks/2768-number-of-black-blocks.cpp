class Solution {
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& c) {
        vector<long long> ans(5,0);
        long l = 1e5 + 2;
        unordered_map<int,int> cp;
        
        for(vector<int> &a:c){
            int x = a[0];
            int y = a[1];
            if(x-1 >= 0 && y-1 >= 0) cp[l*(x-1) + y-1]++;
            if(x+1 < n && y+1 < m) cp[l*x + y]++;
            if(x-1 >= 0 && y+1 < m) cp[l*(x-1) + y]++;
            if(x+1 < n && y-1 >= 0) cp[l*x+y-1]++;
        }
        
        for(auto it:cp) ans[it.second]++;
        
        ans[0] = (n-1)*1LL*(m-1) - accumulate(ans.begin(),ans.end(),0LL);
        return ans;
    }
};