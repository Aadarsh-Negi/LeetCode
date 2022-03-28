class Solution {
public:
    bool search(vector<int>& ar, int tar) {
        
        int l,r;
        l=0;
        r=ar.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(ar[mid]==tar) return 1;
            
            if(ar[mid]==ar[l] && ar[mid]==ar[r]) l++,r--;
            else if(ar[l] <= ar[mid]){
                if(ar[l]<=tar && ar[mid] > tar) r = mid-1;
                else l = mid + 1; 
            }else{
                if(ar[mid] < tar &&  ar[r] >= tar) l = mid+1;
                else r = mid-1;
            }
        }
        return 0;
        
        
    }
};