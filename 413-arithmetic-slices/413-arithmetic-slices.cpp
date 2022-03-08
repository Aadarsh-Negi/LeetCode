class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int c=1;
            int prev;
            for(int j=i+1;j<n;j++){
                if(j==i+1){
                  c++;
                  prev=nums[j]-nums[j-1];  
                }else if(nums[j-1]+prev==nums[j]) c++;
                else break;
            }
            // cout<<c<<"\n";
            if(c>=3){
                ans+=(c-2);
            }
        }
        return ans;
    }
};