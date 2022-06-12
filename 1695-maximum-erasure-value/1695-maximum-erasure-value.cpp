class Solution {
public:
    int maximumUniqueSubarray(vector<int>& s) {
        int ans=0;
        
        vector<int> ck(*max_element(s.begin(),s.end())+1,0);
        int i=0;
        int j=0;
        int sum=0;
        while(i<s.size()){
            while(ck[s[i]]>0){
                ck[s[j]]--;
                sum-=s[j++];
            }
            ck[s[i]]++;
            sum+=s[i];
            i++;
            ans=max(ans,sum);
        }
        
        
        
        return ans;
    }
};