class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int tar) {
        map<int,int> ind;
        for(int i=0;i<ar.size();i++){
            if(ind[tar-ar[i]]) return {ind[tar-ar[i]],i+1};
            ind[ar[i]]=i+1;
        }
        return {};        

    }
};