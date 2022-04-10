class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        vector<char> odd;
        vector<char> ev;
        
        for(char &c:s){
            int v = c-'0';
            if(v&1){
                odd.push_back(c);
            }else ev.push_back(c);
        }
        sort(odd.begin(),odd.end());
        sort(ev.begin(),ev.end());
        
        string ans;
        for(char &c:s){
            int v = c-'0';
            if(v&1){
                ans+=odd.back();
                odd.pop_back();
            }else ans+=ev.back(),ev.pop_back();
        }
        int ss = stoi(ans);
        return ss;
        
    }
};