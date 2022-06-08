class Solution {
public:
    int majorityElement(vector<int>& ar) {
        int cnt=0;
	int mx=ar[0];
	
	for(int &i:ar){
		
		if(i==mx) cnt++;
		else cnt--;
		if(cnt==-1) mx=i,cnt=1;
	}return mx;
    }
};