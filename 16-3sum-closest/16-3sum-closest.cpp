class Solution {
public:
    int threeSumClosest(vector<int> &A, int X) {
     int sum=0;
     int n= A.size();
        int diff=INT_MAX;
        sort(A.begin(),A.end());
        for(int i=0;i<n;i++){
            int l=i+1;
            int h=n-1;
            while(l<h){
                int val=A[i]+A[l]+A[h];
                if(abs(val-X)<diff){
                    diff=abs(val-X);
                    sum=val;
                }
                if(val>X) h--;
                else l++;
                
            }
        }
        return sum;
        // code here
    }
};