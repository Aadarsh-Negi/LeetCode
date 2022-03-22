class Solution {
public:
    string getSmallestString(int n, int k) {
        
        
        
        string ans;
        int c=10;
        while(k){
            char a = 'a';
            if(n==1){
                while((a-'a'+1)!=k) a++;
                ans+=a;
                break;
            }
                
            while((n-1)*26<(k-(a-'a'+1))) a++;
            n--;
            k-=(a-'a'+1);
                  ans+=a;
            // cout<<ans<<"\n";
        }
        return ans;
        
    }
};