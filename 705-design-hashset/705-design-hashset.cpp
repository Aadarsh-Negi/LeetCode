class MyHashSet {
public:
    vector<vector<int>> ar;
    MyHashSet() {
        ar.resize(773);
    }
    
    void add(int key) {
        if(contains(key)) return;
        
        ar[key%773].push_back(key);
    }
    
    void remove(int key) {
       int j=0;
        for(int i:ar[key%773]){
            if(i==key){  
               ar[key%773].erase(ar[key%773].begin()+j);
            }
            j++;
        }
    }
    
    bool contains(int key) {
        for(int i:ar[key%773]){
            if(i==key){  
                return 1;
            }
        }
        
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */