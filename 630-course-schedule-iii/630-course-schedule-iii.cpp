class Solution {
public:
    int scheduleCourse(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end(),[&](const vector<int>&a , const vector<int>&b)
             {
                 
                 
                     if(a[1] == b[1]) 
                 return a[0] > b[0];
                return a[1]<b[1] ;
             });
        
//         for(auto & x : arr)
//         {
//             cout<<x[1]<<" ";
//         }
        
        int pre = 0 ,time = 0 , c = 0;
        priority_queue<int>q;
     
        
        for(int i = 0;i<arr.size();i++)
        {
          if(arr[i][0] + time <= arr[i][1])
          {
              q.push(arr[i][0]);
              time+=arr[i][0];
              c++;
          }
            
          else
          {
              
              if(q.size() && q.top()> arr[i][0])
              {
                  int x = q.top();
                  q.pop();
                  q.push(arr[i][0]);
                  time  += (arr[i][0]-x);
              }
          }
        }
        
        return c;
        return 0;

    }
};