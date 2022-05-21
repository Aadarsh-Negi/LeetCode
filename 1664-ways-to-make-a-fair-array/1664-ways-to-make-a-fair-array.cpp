class Solution {
public:
    int waysToMakeFair(vector<int>& ar) {
        int even=0;
        int odd=0;
        for(int i=0;i<ar.size();i++){
            if(i&1) even+=ar[i];
            else odd+=ar[i];
        }
        
        int ans=0;
        int cur_odd=0;
        int cur_even=0;
        for(int i=0;i<ar.size();i++){
            if(i&1){ // even pos
                // even-=ar[i];
                int nx_even = cur_even + (odd - cur_odd);
                int nx_odd = cur_odd + (even - cur_even-ar[i]);
                if(nx_even == nx_odd) ans++;
                cur_even+=ar[i];
            }else{ // odd pos
                
                // odd-=ar[i];
                int nx_even = cur_even + (odd - cur_odd-ar[i]);
                int nx_odd = cur_odd + (even - cur_even);
                if(nx_even == nx_odd) ans++;
                cur_odd+=ar[i];
            }
        }
        
        return ans;
        
        
    }
};