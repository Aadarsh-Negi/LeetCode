#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; //*find_by_order(k):
template<class T> // order_of_key(k) 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> // use pair // (erase probl)
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        
        omset<int> ox;
        int last = 0;
        for(int i:nums){
            ox.insert(i);    
            if(ox.size() == k){
                if(k&1){
                    int idx = k/2;
                    int val = *ox.find_by_order(idx);
                    ans.push_back(val);
                }else{
                    int idx = k/2;
                    double val = *ox.find_by_order(idx);
                    idx--;
                    double val2 = *ox.find_by_order(idx);
                    val = (val + val2) / 2.0;
                    ans.push_back(val);
                }
                int rank = ox.order_of_key(nums[last++]);
                auto it = ox.find_by_order(rank); 
                ox.erase(it);
            }
            
        }
        
        
        
        
        return ans;
    }
};