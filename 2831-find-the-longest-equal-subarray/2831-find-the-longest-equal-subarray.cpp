class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ind(n+1);
        for(int i=0;i<nums.size();i++){
            ind[nums[i]].push_back(i);
        }

        int ans=1;
        for(int v=1;v<=n;v++){
           int cur = 1;
           int last = 1;
           int temp = 1;
           int rem = k;
           while(cur < ind[v].size()){
               if(rem-(ind[v][cur] - ind[v][cur-1]-1)>=0){
                 rem-=(ind[v][cur] - ind[v][cur-1]-1);
                 temp++;
                 cur++;
               } 
               else{
                    while(rem-(ind[v][cur] - ind[v][cur-1]-1)<0 && last<=cur){
                        rem+=ind[v][last] - ind[v][last-1]-1;
                        temp--;
                        last++;
                    }
                   if(last>cur){
                       cur++;
                       rem = k;
                       temp=1;
                   }
               }
               ans=max(ans,temp);
           }
        }
        return ans;
    }
};