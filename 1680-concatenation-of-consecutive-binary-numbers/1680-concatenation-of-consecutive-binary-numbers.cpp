class Solution {
public:
    int concatenatedBinary(int n) {
        
        long res = 0;
        int const mod = 1e9 + 7;
        for(int i=1;i<=n;i++){
            int val = i;
            while(val) val>>=1,res<<=1;
            res%=mod;
            res+=i;
            res%=mod;
        }
        
        return res;
    }
};