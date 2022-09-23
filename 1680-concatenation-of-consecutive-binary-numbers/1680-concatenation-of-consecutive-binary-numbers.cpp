class Solution {
public:
    int len(int x){
        int res=0;
        while(x){
            x/=2;
            res++;
        }
        return res;
    }
    int concatenatedBinary(int n) {
        
        long long res = 0;
        long long const mod = 1e9 + 7;
        
        for(int i=1;i<=n;i++){
            res<<=len(i);
            res%=mod;
            res+=i;
            res%=mod;
        }
        
        return res;
        
    }
};