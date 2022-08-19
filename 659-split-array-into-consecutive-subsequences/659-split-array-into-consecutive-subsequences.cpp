class Solution {
public:
    bool isPossible(vector<int>& ar) {
       unordered_map<int,int> lf;
       unordered_map<int,int> ed;
        
       for(int i:ar) lf[i]++;
       
        for(int i:ar){
            if(!lf[i]) continue;
            lf[i]--;
            if(ed[i-1]){
                ed[i-1]--;
                ed[i]++;
            }else if(lf[i+1] && lf[i+2]){
                ed[i+2]++;
                lf[i+1]--;
                lf[i+2]--;
            }else return false;
            
        }
    return true;
        
    }
};