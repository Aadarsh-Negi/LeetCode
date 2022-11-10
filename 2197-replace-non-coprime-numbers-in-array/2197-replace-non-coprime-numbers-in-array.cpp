class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(nums[i]);
            }
             else if(__gcd(st.top(),nums[i]) == 1)
            {
                st.push(nums[i]);
            }
            else
            {
                int x = nums[i];
                while(st.size() && __gcd(x,st.top())>1){
                    x = lcm(st.top(),x);
                    st.pop();
                }
                st.push(x);
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            int x = st.top();
            ans.push_back(x);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};