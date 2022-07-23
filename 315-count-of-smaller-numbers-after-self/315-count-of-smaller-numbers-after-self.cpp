class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n,0);
        int const N = 3e4;
        vector<int> fen(N,0);
        auto sum = [&](int i){
            int res=0;
            while(i>0){
                res+=fen[i];
                i-=i&(-i);
            }
            return res;
        };
        auto update = [&](int i){
            while(i<N){
                fen[i]++;
                i+=i&(-i);
            }
        };
        auto idx = [&](int i){
          return i + 1e4+2;  
        };
        
        for(int i=n-1;i>=0;i--){
            int res = sum(idx(nums[i])-1);
            ans[i] = res;
            update(idx(nums[i]));
        }
        
        
        return ans;
    }
};