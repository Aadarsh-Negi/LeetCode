class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int i=0;i<strs[0].size();i++){
            int prev = -1;
            for(int j=0;j<strs.size();j++){
                if(prev > strs[j][i]){
                    ans++; break;
                }
                prev = strs[j][i];
            }
            
        }
            
        return ans;
    }
};