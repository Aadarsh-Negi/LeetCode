class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> cnt;
        
        string temp;
        for(char &c:s){
            temp+=c;
            if(temp.size()>=k){
                cnt.insert(temp);
                temp.erase(temp.begin());
            }
        }
        // for(string sx:cnt) cout<<sx<<" ";
        // k--;
        return cnt.size() == (1<<k);
        
    }
};