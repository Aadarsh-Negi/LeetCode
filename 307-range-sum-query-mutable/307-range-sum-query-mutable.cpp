class NumArray {
public:
    vector<int> btree;
    int n;
    vector<int> n2;
    NumArray(vector<int>& nums) {
        n=nums.size();
        n2=nums;
        for(int i=0;i<=n;i++) btree.push_back(0);
        for(int i=0;i<nums.size();i++)
            update2(i+1,nums[i]);
    }
    void update2(int index, int val) {
        // index++;
        while(index<=n){
            btree[index]+=val;
            index+=index&(-index);
        }
    }
    
    void update(int index, int val) {
      index++;
        update2(index,val-n2[index-1]);
        n2[index-1]=val;
    }
    int getSum(int i){
        int s=0;
        i++;
        while(i>0){
            s+=btree[i];
            i-=i&(-i);
        }
        return s;
    }
    int sumRange(int l, int r) {
        return getSum(r)-getSum(l-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */