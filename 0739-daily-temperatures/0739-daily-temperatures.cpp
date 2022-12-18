class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tt) {
        
        stack<int> st;
        int n = tt.size();
        vector<int> ans(n,0);
        reverse(tt.begin(),tt.end());
        for(int i=0;i<n;i++){
            while(st.size() && tt[st.top()]<=tt[i]) st.pop();
            
            if(st.size()) ans[i] = i-st.top();
            st.push(i);

        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};