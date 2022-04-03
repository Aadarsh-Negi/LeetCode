class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xr = start^goal;
        
        int ans=0;
        while(xr){
            if(xr%2) ans++;
            xr/=2;
        }
        return ans;
    }
};