class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> goingRight;
        
        for(int i:a){
            if(i > 0){
                goingRight.push_back(i);
            }else{
                while(!goingRight.empty() && goingRight.back() > 0 && goingRight.back() < abs(i)) goingRight.pop_back();
                if(!goingRight.empty() && goingRight.back() > 0 && goingRight.back() == abs(i)) goingRight.pop_back();
                else if(goingRight.empty() || goingRight.back() < 0) goingRight.push_back(i);
            }
        }
        return goingRight;
    }
};