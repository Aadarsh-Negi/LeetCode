class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bit(n+1);
        
        auto setVal = [&](int x,int val){
            while(x<=n){
                bit[x]+=val;
                x+=x&(-x);
            }
        };
        auto setRange = [&](int l,int r,int val){
            setVal(l,val);
            setVal(r+1,-val);
        };
        auto valAtIdx = [&](int x){
          int res = 0;
          while(x > 0){
              res+=bit[x];
              x-=x&(-x);
          }  
            return res;
        };
        
        for(int i=0;i<n;i++) setRange(i+1,i+1,nums[i]);
        
        for(int i=0;i<n;i++){
            int x = valAtIdx(i+1);
            if(x > 0 && i+k <= n)
                setRange(i+1,i+k,-x);
            if(valAtIdx(i+1) != 0) return false;
        }
        return true;
    }
};