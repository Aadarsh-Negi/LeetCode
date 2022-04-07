class Solution {
public:
    int findKthPositive(vector<int>& ar, int k) {
        
        int l=0;
        int r=ar.size();
        int ans=0;
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(ar[mid]-(mid+1)>=k) r=mid;
            else l=mid+1;
        }
        
        // k-=ar[ans]-(ans+1);
        return l+k;
        
    }
};