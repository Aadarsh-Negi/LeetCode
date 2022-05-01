class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> ind(26);
        
        int n = s.size();
        for(int i=0;i<s.size();i++){
            int c = s[i] - 'A';
            
            if(ind[c].size()==0) ind[c].push_back(0);
            
            ind[c].push_back(i+1);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(ind[i].size()==0) continue;
            ind[i].push_back(n+1);
            for(int j=1;j<ind[i].size()-1;j++){
                int prev = ind[i][j] - ind[i][j-1];
                prev *= ind[i][j+1] - ind[i][j];
                ans+=prev;
            }
        } 
        return ans;
    }
};