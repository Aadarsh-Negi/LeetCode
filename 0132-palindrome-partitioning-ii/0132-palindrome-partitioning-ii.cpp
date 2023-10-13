class Solution {
public:
    
    bool check(string &s,int i,int j){
        if(i==j)
        return true;

        while(i<j){
            if(s[i++]!=s[j--])
            return false;
        }
       return true;
    }

    int solve(string &s,int i,int j,vector<int> &dp){

        if(i>=j || check(s,i,j))return 0;

        if(dp[i]!=-1)return dp[i];

        int mincut=INT_MAX;

        for(int k=i;k<=j;k++){
            if(check(s,i,k)){
                int temp=1+solve(s,k+1,j,dp);
                mincut=min(mincut,temp);
            }
        }

        return dp[i]=mincut;
    }


    

    int minCut(string s) {
        
        if(s.size()<2)return 0;
        if(check(s,0,s.size()-1))return 0;

        vector<int> dp(s.size(),-1);

        return solve(s,0,s.size()-1,dp);
    }
};