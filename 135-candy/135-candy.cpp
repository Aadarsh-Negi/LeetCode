class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> ok(r.size(),-1);
        
        int mn = min_element(r.begin(),r.end()) - r.begin();
        
        ok[mn]=1;
        int m2 = mn+1;
        int m1 = mn-1;
        while(m2<r.size() || m1>=0){
            while(m2<r.size() && r[m2] > r[m2-1]) ok[m2] = ok[m2-1]+1,m2++;
            while(m1>=0 && r[m1] > r[m1+1]) ok[m1] = ok[m1+1]+1,m1--;
            
            if(m2<r.size()) ok[m2++] = 1;
            if(m1>=0) ok[m1--] = 1;
            // for(int i:ok) cout<<i<<" ";cout<<"\n";
        }
        // cout<<"\n";
    int fl=1;  
    while(fl){
        fl=0;
        // vector<int> temp = ok;
            for(int i=1;i<r.size()-1;i++){
            if(r[i]>r[i+1] && ok[i+1]>=ok[i]){
                ok[i] = ok[i+1]+1;
                fl=1;
            }else if(r[i]>r[i-1] && ok[i-1]>=ok[i]){
                ok[i] = ok[i-1]+1;
                fl=1;
            }
        }
        // if(ok==temp) break;
    }
        // for(int i:ok) cout<<i<<" ";cout<<"\n";
        
        

        
        
        return accumulate(ok.begin(),ok.end(),0);
        
        
    }
};