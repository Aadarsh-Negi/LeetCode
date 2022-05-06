class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        vector<pair<int,char>> cc;
        cc.push_back({0,'?'});
        
        for(char &c:s){
            if(cc.back().second!=c){
                cc.push_back({1,c});
            }else if(++cc.back().first==k) cc.pop_back();
        }
        
        for(auto it:cc){
            ans.append(it.first,it.second);
            
        }
        
        
        return ans;
        
    }
};