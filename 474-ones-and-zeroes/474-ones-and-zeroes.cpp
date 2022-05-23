int dp[104][104][605];
class Solution {
public:
    vector<pair<int,int>> zo;
    int n,m;
    
    int solve(int i,int z,int o){
        if(z<0 || o<0) return INT_MIN/2;
        if(i>=zo.size()) return 0;
        if(dp[z][o][i]!=-1) return dp[z][o][i];
        
        int temp = max({solve(i+1,z,o),1+solve(i+1,z-zo[i].first,o-zo[i].second)});
        return dp[z][o][i]=temp;
    }
    
    int findMaxForm(vector<string>& strs, int m2, int n2) {
        n=n2;
        m=m2;
        for(string &s:strs){
            int z=0;
            for(char &c:s) z+=(c=='0');
            zo.push_back({z,s.size()-z});
            // cout<<z<<" "<<s.size()-z<<"\n";
        }
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,m,n);
        
    
        return ans;
        
    }
};