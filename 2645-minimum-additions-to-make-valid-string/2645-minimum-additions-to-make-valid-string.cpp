class Solution {
public:
    int addMinimum(string &s) {
        string c = "abc";
        
        int i=0;
        int j=0;
        int ans=0;
        while(i<s.size()){
            j%=3;
            if(s[i] == c[j]){
                i++;
                j++;
            }else{
                ans++;
                j++;
            }
        }
        
        return ans + (3-j);
        
    }
};