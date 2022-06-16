// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
        vector<int> search(string pat, string txt)
        {
            int n=txt.size();
            int m=pat.size();
            vector<int> ans;
            vector<int> lps = prefix_function(pat);
            // calc(lps,pat);   
            
            int i=0;
            int j=0;
            while(i<n){
                if(pat[j]==txt[i]){
                    i++;
                    j++;
                }
                if(j==pat.size()){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }else if(i<n && pat[j]!=txt[i]){
                    if(j!=0) j=lps[j-1];
                    else i++;
                }
            }
            
            
            return ans;
        // if(ans.size()==0) return {-1};
        // return ans.size();
            //code hee.
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends