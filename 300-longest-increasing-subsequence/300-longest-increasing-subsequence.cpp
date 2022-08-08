
class Solution {
public:

    
int lengthOfLIS(vector<int>& a) {
     vector<int> lis;
     for (int i = 0; i < a.size(); i++) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it != lis.end()) *it = a[i];
        else lis.push_back(a[i]);
    }
    return lis.size();
}
};