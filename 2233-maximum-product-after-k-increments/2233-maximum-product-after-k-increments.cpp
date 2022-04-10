#define ll long long
const ll mod=1000000007;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> qq(nums.begin(),nums.end());
        
        while(k--){
            int t  = qq.top(); qq.pop();
            t++;
            qq.push(t);
        }
        ll ans=1;
        while(qq.size()){
            ans*=qq.top(); qq.pop();
            ans%=mod;
        }
        return ans;
        
    }
};