
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define m_os tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        m_os cnt;
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--){
            cnt.insert(nums[i]);
            
            
            ans[i] = cnt.order_of_key(nums[i]);
            
        }
        
        
        return ans;
    }
};