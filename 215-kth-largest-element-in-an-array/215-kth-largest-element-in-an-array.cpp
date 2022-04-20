class Solution {
public:
    int qk(vector<int> &ar,int l,int h,int k){
        if(l<=h){
            int mid = part(ar,l,h);
            if(mid==ar.size()-k) return ar[mid];
             if(mid<ar.size()-k){
                return qk(ar,mid+1,h,k);
            }
            return qk(ar,l,mid-1,k);
        }
        return -1;
    }
    int part(vector<int> &ar,int l,int h){
        int last = l-1;
        int pt = ar[h];
        for(int j=l;j<h;j++){
            if(ar[j]<pt){
                last++;
                swap(ar[j],ar[last]);
            }
        }
        swap(ar[last+1],ar[h]);
        return last+1;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        return qk(nums,0,nums.size()-1,k);
    }
};