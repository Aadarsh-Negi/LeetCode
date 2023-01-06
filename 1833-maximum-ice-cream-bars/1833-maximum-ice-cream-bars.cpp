class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        sort(costs.begin(),costs.end());
        int i=0;
        while(i<costs.size()){
            if(coins >= costs[i]){
                ans++;
                coins-=costs[i];
            }
            i++;
        }
        return ans;
    }
};