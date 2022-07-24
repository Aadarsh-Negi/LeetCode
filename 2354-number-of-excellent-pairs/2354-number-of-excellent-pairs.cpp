#define ll long long
class Solution {
public:
    unsigned ll countSetBits(ll n){
    unsigned ll count = 0;
    while (n) {
        if(n&1)
            count++;
        n/=2;
    }
    return count;
}
    ll pairs(vector<int>& arr, ll k){
    ll n = arr.size();
    ll count = 0;
        set<int> sx(arr.begin(),arr.end());
    ll f[60 + 1] = { 0 };
    for (int i:sx)
        f[countSetBits(i)]++;
 
    for (ll i = 0; i <= 60; i++) {
        for (ll j = 1; j <= 60; j++) {
             if (i + j >= k) {
                    count += (f[i] * f[j]);
            }
        }
    }
    return count;
}
    long long countExcellentPairs(vector<int>& nums, int k) {
        return pairs(nums,k);
    }
};