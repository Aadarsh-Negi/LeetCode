class Solution {
public:
    string smallestNumber(string &pp) {
       string ans = "9999999999999";
        char ar[] = {'1','2','3','4','5','6','7','8','9'};
        do{
            int idx=0;
            bool ok=1;
            for(int i=0;i<pp.size();i++){
                if(pp[i]=='I'){
                    if(ar[idx] >= ar[idx+1]){ ok=0;}
                }else{
                    if(ar[idx] <= ar[idx+1]) {ok=0; }
                }
                idx++;
            }
            if(ok){
                string temp;
                for(int i=0;i<=pp.size();i++) temp+=ar[i];
                ans=min(ans,temp);
            }
        }while(next_permutation(ar,ar+9));
        
        return ans;
        
    }
};