class Solution {
public:
    vector<int> searchRange(vector<int>& ar, int tar) {
        vector<int> ans = {-1,-1};
        
        {
            int l=0;
            int r=ar.size()-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(ar[mid] == tar) ans[0] = mid,r=mid-1;
                else if(ar[mid]>tar) r=mid-1;
                else l=mid+1;
            }
        }
        {
            int l=0;
            int r=ar.size()-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(ar[mid] == tar) ans[1] = mid,l=mid+1;
                else if(ar[mid]>tar) r=mid-1;
                else l=mid+1;
            }
        }

        return ans;
    }
};