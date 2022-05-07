class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> mn2(n);
        mn2[0]=nums[0];
        
        for(int i=1;i<n;i++) mn2[i]=min(mn2[i-1],nums[i]);
        stack<int> ck;
        // for(int i:mn2) cout<<i<<" ";cout<<"\n";
        for(int i=n-1;i>=0;i--){
            if(nums[i]>mn2[i]){
                // cout<<nums[i]<<" <Can\n";
                while(ck.size() && ck.top()<=mn2[i]) ck.pop();
                if(ck.size() && ck.top()<nums[i]) {return 1;}    
                ck.push(nums[i]);
            }
            
            
        }
        return 0;
	
    }
};