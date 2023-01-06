class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        while(i<costs.size()){
            if(coins < costs[i])
                return i;
            coins-=costs[i++];
        }
        return i;
    }
};