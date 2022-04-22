class MyHashMap {
public:
    vector<vector<pair<int,int>>> ar;
    MyHashMap() {
        ar.resize(1003);
    }
    
    void put(int key, int value) {
        if(get(key)==-1){
            ar[key%997].push_back({key,value});
        }else{
            for(pair<int,int> &aa:ar[key%997]){
                int x = aa.first;
                int y = aa.second;
                if(x==key){
                    aa.second = value;
                    return;
                }
            }    
        }
    }
    
    int get(int key) {
        for(pair<int,int> &aa:ar[key%997]){
            int x = aa.first;
            int y = aa.second;
            if(x==key) return y;
        }
        return -1;
    }
    
    void remove(int key) {
       int j=0;
        for(pair<int,int> &i:ar[key%997]){
            if(i.first==key){  
               ar[key%997].erase(ar[key%997].begin()+j);
                return;
            }
            j++;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */