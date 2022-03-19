class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
      
        vector<int> cnt;
        cnt.push_back(0);
        int prev=-1;
        for(int &i:nums){
            if(i==0) cnt.push_back(0);
            else{
                if(prev==-1 || prev==0) cnt.push_back(1);
                else cnt.back()++;
            }
            prev=i;
        }
         // for(int &i:cnt) cout<<i<<" ";
        cnt.push_back(0);
        int ans=-1;
        for(int i=1;i<cnt.size()-1;i++){
            if(cnt[i]==0){
                ans=max(ans,cnt[i-1]+cnt[i+1]);
            }
        }
        if(ans==-1){
            return *max_element(cnt.begin(),cnt.end())-1;
        }
        
        
        return ans;
        
        
    }
};