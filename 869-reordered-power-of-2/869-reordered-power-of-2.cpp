class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string val = to_string(n);
        sort(val.begin(),val.end());
        bool ok=false;
        do{
            if(val.front()!='0'){
                int x = stoi(val);
                ok|=(x&(x-1))==0;
            }
            
        }while(next_permutation(val.begin(),val.end()));
        
        return ok;
    }
};