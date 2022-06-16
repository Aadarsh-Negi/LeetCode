class Solution {
public:
    string longestPalindrome(string s) {
        int cnt=1;
        string ans;
        for(int i=0;i<s.size();i++){
            int j=i-1;
            int k=i+1;
            string fs;
            string ls;
            ls+=s[i];
            // ls+='?';
            while(j>=0 && k<s.size() && s[j]==s[k]) fs+=s[j],ls+=s[k],j--,k++;
            if(cnt < (k-j)){
                cnt = k-j;
                reverse(fs.begin(),fs.end());
                
                ans=fs+ls;
                
            }
            
            j=i-1;
            k=i;
            fs.clear();
            ls.clear();
            while(j>=0 && k<s.size() && s[j]==s[k]) fs+=s[j],ls+=s[k],j--,k++;
            if(cnt < (k-j)){
                cnt = k-j;
                reverse(fs.begin(),fs.end());
                ans=fs+ls;
            }

        }
        
        
        return ans;
    }
};