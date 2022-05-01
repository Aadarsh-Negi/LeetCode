class Solution {
public:
    int uniqueLetterString(string s) {
        map<char,vector<int>> ind;
        
        int n = s.size();
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(ind[c].size()==0){
                ind[c].push_back(0);
                ind[c].push_back(n+1);
            }
            ind[c].push_back(i+1);
        }
        int ans=0;
        for(auto &it:ind){
            sort(it.second.begin(),it.second.end());
            
            for(int i=1;i<it.second.size()-1;i++){
                int prev = it.second[i] - it.second[i-1];
                prev *= it.second[i+1] - it.second[i];
                ans+=prev;
            }
        } 
        return ans;
    }
};