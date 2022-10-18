class Solution {
public:
    string countAndSay(int n) {
       string ans(2,'1');
        
        if(n==1) return "1";
        if(n==2) return ans;
        for(int i=3;i<=n;i++){
            int cnt=1;
            char c=ans[0];
            string temp="";
            for(int j=1;j<ans.size();j++){
                if(c==ans[j]) cnt++;
                else{
                    temp.push_back('0'+cnt);
                    temp.push_back(c);
                    c=ans[j];
                    cnt=1;
                }
            }
            temp.push_back('0'+cnt);
            temp.push_back(c);
            // ans.clear();
            ans=temp;
        }
        
        
        return ans;
    }
};