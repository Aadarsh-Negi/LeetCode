class Solution {
public:
    bool isPossible(vector<int>& ar) {
       int lf[2105]={0};
       int ed[2105]={0};
        
       for(int i:ar) lf[i+1010]++;
       
        for(int i:ar){
            i+=1010;
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