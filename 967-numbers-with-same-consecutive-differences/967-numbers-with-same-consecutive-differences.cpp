class Solution {
public:
    
    void solve(vector<int> &ans,int n,int k,int val=0){
        if(n==1){
            ans.push_back(val);
            return;
        }
     
            int i = val%10;
            if(i+k<=9) solve(ans,n-1,k,val*10 + i+k);
            if(i+k!=i-k && i-k>=0) solve(ans,n-1,k,val*10 + i-k);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
            solve(ans,n,k,i);
        return ans;
    }
};