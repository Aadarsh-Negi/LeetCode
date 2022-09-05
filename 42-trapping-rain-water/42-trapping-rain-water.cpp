class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int maxLeft[size];
        int maxRight[size];
        
        maxLeft[0] = height[0];
        maxRight[size-1] = height[size-1];
        
        for(int pos=1;pos<size;pos++) maxLeft[pos] = max(maxLeft[pos-1],height[pos]);
        for(int pos=size-2;pos>=0;pos--) maxRight[pos] = max(maxRight[pos+1],height[pos]);
        
        int water = 0;
        for(int pos = 1; pos < size-1; pos++){
            int can = min(maxLeft[pos-1],maxRight[pos+1]);
            water+=max(0,can-height[pos]);
        }
        
        return water;
        
        
    }
};