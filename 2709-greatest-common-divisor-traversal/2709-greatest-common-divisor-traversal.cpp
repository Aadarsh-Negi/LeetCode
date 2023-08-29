int par[200055];
class Solution {
public:
    int find(int x){
        if(par[x] == -1) return x;
        return par[x] = find(par[x]);
    }
    void ux(int a,int b){
        a = find(a);
        b = find(b);
        if(a != b){
            par[a] = b;
        }
    }
    bool canTraverseAllPairs(vector<int>& a) {
        memset(par,-1,sizeof(par));        
        int base = 1e5 + 1;
        for(int j=0;j<a.size();j++){
            int n = a[j];
            for(int i=2;i*i<=n;i++){
                if(n%i == 0){
                    while(n%i == 0) n/=i;
                    ux(i,base + j);           
                }
            }
            if(n > 1) ux(n,base+j);
        }
        set<int> xx;
       for(int j=0;j<a.size();j++) xx.insert(find(base + j));
        return xx.size() == 1;
    }
};