class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string val = to_string(n);
        sort(val.begin(),val.end());
        bool ok=false;
        do{
            if(val.front()!='0'){
                int x = stoi(val);
                while(x && x%2==0) x/=2;
                ok|=(x==1);
            }
            
        }while(next_permutation(val.begin(),val.end()));
        
        return ok;
    }
};