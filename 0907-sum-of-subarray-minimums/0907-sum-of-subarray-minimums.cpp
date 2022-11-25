class Solution {
public:
    vector<int> lf;
    vector<int> rf;
    void right(vector<int> &ar){
        stack<int> ck;
        for(int i=ar.size()-1;i>=0;i--){
            // if(ck.size()){
                while(ck.size() && ar[ck.top()]>ar[i]) ck.pop();
                
                if(ck.size()) rf[i] = ck.top();
                // else lf[i] = ar.size();
                
                ck.push(i);
            
        }
        
    }
    void left(vector<int> &ar){
        stack<int> ck;
        for(int i=0;i<ar.size();i++){
            // if(ck.size()){
                while(ck.size() && ar[ck.top()]>=ar[i]) ck.pop();
                
                if(ck.size()) lf[i] = ck.top();
                // else rf[i] = -1;
                
                ck.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& ar) {
       
        int n=ar.size();
        int const mod = 1e9+7;
        lf.assign(n,-1);
        rf.assign(n,ar.size());
        
         
        left(ar);
        right(ar);
      
        int ans=0;
        for(int i=0;i<ar.size();i++){
            long long val = ((long long)(i-lf[i]) * (rf[i]-i)%mod) * ar[i]%mod;
            ans = (ans%mod + val%mod)%mod;
            // ans%=mod;
            
        }
        return ans;
        
        
        

        
    }
};