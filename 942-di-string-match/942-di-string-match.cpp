class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int f=0;
        int l=s.size();
        s+='.';
        
        for(char &c:s){
            if(c=='I') ans.push_back(f++);
            else ans.push_back(l--);    
        }
        // ans.push_back(f);
        return ans;
    }
};