//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> combinationSum(int K, int N) {
            
            
            vector<vector<int>> ans;
            
            
            
            for(int i=1;i<(1<<9);i++){
                
                vector<int> temp;
                int s = 0;
                
                for(int j=0;j<9;j++){
                    if(i&(1<<j)){
                        s+=(j+1);
                        temp.push_back(j+1);
                    }
                }
                if(s == N && temp.size() == K){
                    ans.push_back(temp);
                }
            }
            return ans;
            
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends