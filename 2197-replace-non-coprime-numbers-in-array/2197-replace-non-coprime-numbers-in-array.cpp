class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        
        for(int i:nums){
                int c = i;
                while(ans.size() && gcd(ans.back(),c)>1){
                    c = lcm(ans.back(),c);
                    ans.pop_back();
                }
                ans.push_back(c);                
        }
        return ans;
    }
};