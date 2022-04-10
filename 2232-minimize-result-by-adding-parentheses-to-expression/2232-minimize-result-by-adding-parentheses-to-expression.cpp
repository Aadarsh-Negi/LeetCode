#define ll long long
class Solution {
public:
        ll mn;
        string ans;
        int mid;
    void solve(int left,int right,string &exp){
        if(left<0 || right>=exp.size()) return;
        
        string l,r,n1,n2;
        
        for(int i=left;i<mid;i++) l+=exp[i];
        for(int i=mid+1;i<=right;i++) r+=exp[i];
        for(int i=0;i<left;i++) n1+=exp[i];
        for(int i=right+1;i<exp.size();i++) n2+=exp[i];
        
        ll l2,r2,n12,n22;
        n12=n22=1;
        l2=r2=0;
        
        if(l.size()) l2 = stoll(l);
        if(r.size()) r2 = stoll(r);
        if(n1.size()) n12 = stoll(n1);
        if(n2.size()) n22 = stoll(n2);
        
        ll val = n12 *(l2+r2)*n22;
        if(val<mn){
            mn=val;
            ans="";
            for(int i=0;i<exp.size();i++){
                if(i==left) ans+='(';
                
                ans+=exp[i];
                
                if(i==right) ans+=')';
            }
        }
        solve(left-1,right,exp);
        solve(left,right+1,exp);
        solve(left-1,right+1,exp);  
    }
        
    
    
    string minimizeResult(string exp) {
        mn=1e12;
        mid=0;
        while(exp[mid]!='+') mid++;
        solve(mid-1,mid+1,exp);
        
        return ans;
        
    }
};