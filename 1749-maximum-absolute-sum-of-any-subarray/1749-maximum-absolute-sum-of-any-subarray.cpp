class Solution {
public:
    
    int solve(vector<int> &a,int x){

   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < a.size(); i++)
   {
       if(x){
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);   
       }else{
           curr_max = min(a[i], curr_max+a[i]);
            max_so_far = min(max_so_far, curr_max);   
       } 
        
   }
        return abs(max_so_far);
    }
    
    int maxAbsoluteSum(vector<int>& nums) {
       return max(solve(nums,1),solve(nums,0));
        
    }
};