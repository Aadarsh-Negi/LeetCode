class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=i;j<n;j++){
                temp+=arr[j];
                if((j-i+1)&1) ans+=temp;
            }
        }
        return ans;
    }
};