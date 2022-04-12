class Solution {
public:
    int k;
    int partition(vector<int> &ar,int l,int r){
    int pivot = ar[r];
    int i = l-1;
    
    for(int j=l;j<=r-1;j++){
        if (ar[j] < pivot)
        {
            i++; 
            swap(ar[i],ar[j]);
        }
    }
        swap(ar[i+1],ar[r]);
    return i+1;
}


    int findKthLargest(vector<int> nums, int k) {
      int start = 0, end = nums.size() - 1, index = nums.size() - k;
        while (start < end) {
            int pivot = partition(nums, start, end);
            if (pivot < index) start = pivot + 1; 
            else if (pivot > index) end = pivot - 1;
            else return nums[pivot];
        }
        return nums[start];
    }
};