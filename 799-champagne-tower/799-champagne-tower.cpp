class Solution {
public:
    double gg[304][304];
    
    double champagneTower(int poured, int row, int glass) {
       
        
        memset(gg,0.0,sizeof(gg));
        gg[0][0]=poured;
        
        
        double t2 = 2.0;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                
               double next = (gg[i][j]-1.0)/2.0;
                if(next>0){
                    gg[i+1][j]+=next;
                    gg[i+1][j+1]+=next;
                    
                }
                
            }
            
        }
        // for(int i=1;i<=10;i++){
        //     for(int j=1;j<=i;j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
                                                       
        return min(1.0,gg[row][glass]);
        
                                 
        
    }
};