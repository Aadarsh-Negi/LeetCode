class Solution {
public:
    int n;
    vector<int> ar;
    vector<int> pref;
    int solve(int i,int cur_even,int cur_odd,int fl){
        if(i>n){
            if(!fl) return 0;
            return cur_even==cur_odd;
        }
        // if(dp.count({i,fl})) r
        int temp=0;
        if(fl){ // fl=1 if removed
           if(i&1){
               temp+=solve(n+1,cur_even+pref[i],cur_odd+pref[i+1],1);
           }else{
               temp+=solve(n+1,cur_even+pref[i+1],cur_odd+pref[i],1);
           }
            
        }else{
            if(i&1){
                temp+=solve(i+1,cur_even,cur_odd+ar[i-1],0);
                temp+=solve(i+1,cur_even,cur_odd,1);  
            }else{
                temp+=solve(i+1,cur_even+ar[i-1],cur_odd,0);  
                temp+=solve(i+1,cur_even,cur_odd,1);
                
            }
        }
        return temp;
        
    }
    
    
    int waysToMakeFair(vector<int>& ar2) {
//         ttl_even=0;
//         ttl_odd=0;
        ar=ar2;
        n=ar.size();
        
        pref.resize(n+3,0);
        pref[n] = ar2[n-1];
        if(n>=2)
            pref[n-1] = ar2[n-2];
        for(int i=n-2;i>0;i--) pref[i]+=pref[i+2]+ar[i-1];
        
        return solve(1,0,0,0);
    }
};