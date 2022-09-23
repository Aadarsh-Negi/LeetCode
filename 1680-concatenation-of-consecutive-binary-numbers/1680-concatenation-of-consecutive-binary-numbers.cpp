class Solution {
public:
    int concatenatedBinary(int n) {
        
        long res = 0;
        int const mod = 1e9 + 7;
        
        for(int i=1;i<=n;i++){
            int len=0;
            while((1<<len)<=i) len++;
            res<<=len;
            res%=mod;
            res+=i;
            res%=mod;
        }
        
        return res;
        
    }
};