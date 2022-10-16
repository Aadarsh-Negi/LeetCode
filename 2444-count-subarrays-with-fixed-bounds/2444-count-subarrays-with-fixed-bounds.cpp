int const K = 19;
const int MAXN = 1e5 + 2;

int mn[MAXN][K + 1];
int mx[MAXN][K + 1];
int lg[MAXN+1];
void build(vector<int> &ar){
int N = ar.size();
lg[1] = 0;
for (int i = 2; i <= MAXN; i++)
    lg[i] = lg[i/2] + 1;
for (int i = 0; i < N; i++){
    mn[i][0] = ar[i];
    mx[i][0] = ar[i];
}
    
for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++){
        mn[i][j] = min(mn[i][j-1], mn[i + (1 << (j - 1))][j - 1]);
        mx[i][j] = max(mx[i][j-1], mx[i + (1 << (j - 1))][j - 1]);
    }
}
int getm(int L,int R){
    int j = lg[R - L + 1];
    return min(mn[L][j], mn[R - (1 << j) + 1][j]);
}
int getmx(int L,int R){
    int j = lg[R - L + 1];
    return max(mx[L][j], mx[R - (1 << j) + 1][j]);
}

class Solution {
public:
    long long countSubarrays(vector<int>& ar, int minK, int maxK) {
        long long ans = 0;
        int n = ar.size();
        build(ar);
        auto ff = [&](int x){
            // if(mn.get(x,n-1)<minK || mx.get(x,n-1)>maxK) return 0LL;
            int L = -1;
            int R = n+1;
            
            {
                int f,ls;
                f = ls = -1;
                {   
                    int l = x;
                    int r = n-1;
                    while(l<=r){
                        int mid = l + (r-l)/2;
                        int mm = getm(x,mid);
                        if(mm == minK){
                            f = mid;
                            r = mid-1;
                        }else if(mm < minK) r = mid-1;
                        else l = mid+1;
                    }
                }
                {   
                    int l = x;
                    int r = n-1;
                    while(l<=r){
                        int mid = l + (r-l)/2;
                        int mm = getm(x,mid);
                        if(mm == minK){
                            ls = mid;
                            l = mid+1;
                        }else if(mm > minK) l = mid+1;
                        else r = mid-1;
                    }
                }
                if(f==-1 || ls==-1) return 0LL;
                L = max(L,f);
                R = min(R,ls);
            }
            {
                int f,ls;
                f = ls = -1;
                {   
                    int l = x;
                    int r = n-1;
                    while(l<=r){
                        int mid = l + (r-l)/2;
                        int mm = getmx(x,mid);
                        if(mm == maxK){
                            f = mid;
                            r = mid-1;
                        }else if(mm < maxK) l = mid+1;
                        else r = mid-1;
                    }
                }
                {   
                    int l = x;
                    int r = n-1;
                    while(l<=r){
                        int mid = l + (r-l)/2;
                        int mm = getmx(x,mid);
                        if(mm == maxK){
                            ls = mid;
                            l = mid+1;
                        }else if(mm < maxK) l = mid+1;
                        else r = mid-1;
                    }
                }
                if(f==-1 || ls==-1) return 0LL;
                L = max(L,f);
                R = min(R,ls);
            }
            
            
            return max(0LL + R - L + 1,0LL);
        };
        
        for(int i=0;i<n;i++){
            if(ar[i] < minK || ar[i]>maxK) continue;
            ans+=ff(i);
        }
        return ans;
        
    }
};