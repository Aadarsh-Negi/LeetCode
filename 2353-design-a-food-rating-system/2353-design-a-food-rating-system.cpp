class FoodRatings {
public:
    map<string,set<pair<int,string>>> cx;
    map<string,int> rx;
    map<string,string> fx;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            int i=0;
            for(string &s:cuisines){
                cx[s].insert({-ratings[i],foods[i]});
                rx[foods[i]] = ratings[i];
                fx[foods[i]] = s;
                i++;
            }    
    }
    
    void changeRating(string food, int newRating) {
        pair<int,string> prev = {-rx[food],food};
        string cc = fx[food];
        cx[cc].erase(prev);
        cx[cc].insert({-newRating,food});
        rx[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cx[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */