class Solution {
public:
    string digitSum(string s, int k) {
        string s2 = s;
        while(s2.size()>k){
            s2+='?';
            int t=k;
            string ss;
            string temp;
            for(char &c:s2){
                if(t==0 || c=='?'){
                    int cnt=0;
                    for(char &c:temp) cnt+=(c-'0');
                    ss+=to_string(cnt);
                    t=k-1;
                    temp = c;
                }else temp+=c,t--;
                
                // cout<<temp<<"\n";
            }
            
            s2=ss;
        }
        return s2;
    }
};