class Solution {
public:
    string longestPalindrome(string s) {
        int l = -1;
        int r = -1;
        
        for(int i=0;i<s.size();i++){
            int l1 = i;
            int l2 = i;
            while(l1>=0 && l2 < s.size() && s[l1] == s[l2]){
                if(r-l <= (l2-l1)){
                        l = l1;
                        r = l2;
                    }
                l1--;
                l2++;
            }
            {
                int l1 = i;
                int l2 = i+1;
                while(l1>=0 && l2 < s.size() && s[l1] == s[l2]){
                    if(r-l <= (l2-l1)){
                        l = l1;
                        r = l2;
                    }
                    l1--;
                    l2++;
                }

                
            }   
        }
        
            
        return s.substr(l,r-l+1);
    }
};