class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        
        int cur=1;
        for(int &i:digits){
            i+=cur;
            cur=i/10;
            i%=10;
        }
        if(cur) digits.push_back(cur);
        
        reverse(digits.begin(),digits.end());
        
        return digits;
        
        
    }
};