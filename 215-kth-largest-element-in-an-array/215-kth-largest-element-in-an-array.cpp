class Solution {
public:
    int qs(vector<int> &nums,int l,int h,int k){
        if(l>h) return -1;
        
        int mid = split(nums,l,h);
        
        if(mid == nums.size() - k) return nums[mid];
        
        if(mid > nums.size()-k) return qs(nums,l,mid-1,k);
        return qs(nums,mid+1,h,k);
        
        
    }
    
    int split(vector<int> &ar,int l,int h){
        int last = l;
        while(l<h){
            if(ar[l]<ar[h]){
                swap(ar[l],ar[last++]);
            }
            l++;
        }
        swap(ar[h],ar[last]);
        return last;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return qs(nums,0,nums.size()-1,k);
    }
};