class Bitset {
public:
    vector<int>bitset,invertedBitset;
    int ones=0,zeros=0;
    Bitset(int size) {
        for(int i=0;i<size;i++)
        {
            bitset.push_back(0);            
            invertedBitset.push_back(1);
        }
        zeros=size;
    }
    
    void fix(int idx) {
        if(bitset[idx]==0){
        ones++;
        zeros--;
        }
        bitset[idx]=1;        
        invertedBitset[idx]=0;
    }
    void unfix(int idx) {
        if(bitset[idx]==1){
        ones--;
        zeros++;
        }
        bitset[idx]=0;        
        invertedBitset[idx]=1;
    }
    
    void flip() {
        // swap(bitset,invertedBitset);
        bitset.swap(invertedBitset);
        swap(ones,zeros);
    }
    
    bool all() {
        return ones==bitset.size();
    }
    
    bool one() {
        return ones>0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string res;
        for(auto i:bitset){
            res.push_back(i+'0');
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */