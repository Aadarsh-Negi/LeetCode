class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int> ll;
        for(int i:people){
            ll.insert(i);
        }
        int ans=0;
        for(int i:people){
            if(ll.count(i)){
                ll.erase(ll.lower_bound(i));
                int rem = limit-i;
                auto it = ll.upper_bound(rem);
                if(it!=ll.begin()) ll.erase(--it);
                
                ans++;
                
            }
        }
        
        return ans;
    }
};