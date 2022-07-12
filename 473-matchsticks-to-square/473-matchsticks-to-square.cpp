class Solution {
public:
    bool makesquare(vector<int>& ar) {
        int n = ar.size();
        int ss=0;
        for(int &i:ar) ss+=i;
        
        if(ss%4) return false;
        
        ss/=4;
        
        vector<int> prev_valid;
        vector<bool> valid_2(1<<n,false);
        
        for(int i=0;i<(1<<n);i++){
            
            int c=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) c+=ar[j];
            }
            if(c==ss){
                for(int &k:prev_valid){
                    if(k&i);
                    else{
                        if(valid_2[((1<<n)-1)^(k|i)]) return 1;
                        valid_2[k|i] = 1;
                    }
                }
                prev_valid.push_back(i);
            }
        }
        return 0;
        
        
    }
};