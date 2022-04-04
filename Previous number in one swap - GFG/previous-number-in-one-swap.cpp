// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string S){
        
        if(is_sorted(S.begin(),S.end())) return "-1";
        
        map<int,set<int>> index;
        
        for(int i=0;i<S.size();i++){
            index[S[i]].insert(i);
        }
        
        for(int i=S.size()-1;i>=0;i--){
            
            char st = (i==0?'1':'0');
            char c = S[i];
            c--;
            for(;c>=st;c--){
                
                auto it = index[c].lower_bound(i);
                if(it!=index[c].end()){
                    swap(S[i],S[*it]);
                    return S;
                }
                
            }
        }
        return "-1";
        
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends