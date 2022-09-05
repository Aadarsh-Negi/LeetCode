class Solution {
public:
    vector<string> ans;
    void solve(int n,int n2,string temp){
        if(n==0 && n2==0){ if(temp.size()) ans.push_back(temp); return;}
        
        if(n) solve(n-1,n2,temp+'(');
        
        if(n2){
            if(n<n2) solve(n,n2-1,temp+')');
            // solve(n)
        } 
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");
        return ans;
    }
};