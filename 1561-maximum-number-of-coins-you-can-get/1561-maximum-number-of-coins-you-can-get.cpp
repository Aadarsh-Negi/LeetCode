class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int ans = 0;
        int n = piles.size();
        n/=3;
        for(int i=1;i<piles.size()-n;i+=2) ans+=piles[i];
        return ans;
    }
};