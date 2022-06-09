class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int tar) {
        
        int i=0;
        int j=ar.size()-1;
        
        while(i<j){
            if(ar[i] + ar[j] == tar) return {i+1,j+1};
            else if(ar[i]+ar[j] > tar) j--;
            else i++;
        }
        return {};

    }
};