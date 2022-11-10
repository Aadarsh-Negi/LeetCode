class Solution {
public:
    string removeDuplicates(string &s,int i=0){
        string ans;
        for(char &c:s){
            if(ans.size() && ans.back()==c){
                ans.pop_back();
            }else ans+=c;
        }
        return ans;
    }
};