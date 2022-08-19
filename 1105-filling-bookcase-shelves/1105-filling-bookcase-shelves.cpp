int dp[1005][1005];
class Solution {
public:
    int solve(vector<vector<int>> &books,int &mx,int i=0,int cur=0,int h=0){
        if(i>=books.size()) return h;
        
        if(dp[i][cur]!=-1) return dp[i][cur];
        
        int temp = INT_MAX;
        if(cur + books[i][0] <= mx)
            temp = solve(books,mx,i+1,cur+books[i][0],max(h,books[i][1]));
        
        temp = min(temp,h+solve(books,mx,i+1,books[i][0],books[i][1]));
        
        return dp[i][cur]=temp;
        
    }
    int minHeightShelves(vector<vector<int>>& books, int mx) {
        memset(dp,-1,sizeof(dp));
        return solve(books,mx);
    }
};