class Solution {
public:
    vector<int> dp;
    int solve(int i,string &s){
        if(i<0) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int temp=0;
        if(s[i]==')' && s[i-1]=='('){
            temp = 2 + solve(i-2,s);
        }else if(s[i]==')' && s[i-1]==s[i]){
            int l = solve(i-1,s);
            if(i-1-l>=0 && s[i-1-l]=='('){
                temp = l + 2 + solve(i-l-2,s);
            }
        }
        return dp[i]=temp;
    }
    int longestValidParentheses(string s) {
        dp.resize(s.size()+1,-1);
        dp[0]=0;
        int ans=0;
        for(int i=1;i<s.size();i++){
            ans=max(ans,solve(i,s));
        }
        return ans;
    }
};