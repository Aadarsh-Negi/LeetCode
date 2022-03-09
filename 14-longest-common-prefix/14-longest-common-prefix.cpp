class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        
        for(int i=0;i<strs[0].size();i++){
            
            bool ok=1;
            for(int j=0;j<strs.size();j++){
                ok&=(strs[j][i]==strs[0][i]);
            }
            if(ok) ans+=strs[0][i];
            else return ans;
        }
        return ans;
        
        
    }
};