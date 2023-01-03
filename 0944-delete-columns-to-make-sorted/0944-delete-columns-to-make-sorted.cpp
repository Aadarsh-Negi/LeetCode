class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int i=0;i<strs[0].size();i++){
            string s;
            for(int j=0;j<strs.size();j++){
                s+=strs[j][i];
            }
            ans+=!is_sorted(s.begin(),s.end());
        }
            
        return ans;
    }
};