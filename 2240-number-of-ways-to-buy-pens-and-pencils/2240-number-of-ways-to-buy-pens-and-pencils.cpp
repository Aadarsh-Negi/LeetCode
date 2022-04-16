class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        
       // if(cost1>cost2) swap(cost1,cost2);
        
        for(int i=0;i<=(total/cost1);i++){ 
            long long v1 = i*cost1;
            long long rem = total - v1;
            long long mx = rem/cost2 + 1;
            ans+=mx;        
        }
        return ans;
    }
};