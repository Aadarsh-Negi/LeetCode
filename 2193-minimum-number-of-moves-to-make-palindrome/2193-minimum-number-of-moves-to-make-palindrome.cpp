class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        
        while(s.size()){
            int j = s.find(s.back());
            if(j!=s.size()-1){
                ans+=j;
                s.erase(j,1);
            }else{
                ans+=(s.size()/2);
            }
            s.pop_back();
        }
        return ans;
    }
};