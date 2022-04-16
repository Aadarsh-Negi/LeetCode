class ATM {
public:
    vector<long long> ttl;
    vector<long long> ind;
    ATM() {
        ind.resize(5);
        ttl.resize(5);
        ind[0]=20;
        ind[1]=50;
        ind[2]=100;
        ind[3]=200;
        ind[4]=500;
        
    }
    
    void deposit(vector<int> bb) {
        for(int i=0;i<bb.size();i++){
            ttl[i]+=bb[i];
        }
        // for(int i:ttl) cout<<i<<" ";cout<<"\n";
    }
    
    vector<int> withdraw(long long at) {
        vector<int> ans(5,0);
        vector<long long> org =ttl;
        for(int i=4;i>=0 && at>0;i--){
        if(ind[i]<=at){            
            long long cc = ttl[i]*ind[i]*1LL;
            if(cc<=at){
                at-=cc;
                ans[i]=ttl[i];
                ttl[i]=0;
                
            }else{
                long long req = at/ind[i];
                at-=1LL*req*ind[i];
                ttl[i]-=req;
                ans[i]=req;
                // break;
            }}
        }
        
        if(at==0LL) return ans;
        ttl = org;
        return {-1};
      
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */