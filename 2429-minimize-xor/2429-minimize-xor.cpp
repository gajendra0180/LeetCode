class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32>bt(num2);
        int cb=bt.count();
        bitset<32>b(num1);//000000000000000000000011
        string bn=b.to_string();
        // cout<<bn<<endl;
        for(auto &i:bn){
            if(i=='1' && cb > 0)
                cb--;
            else
                i='0';
        }
        for(int i=bn.size()-1;i>=0;i--){
            if(cb>0 && bn[i]=='0'){
                bn[i]='1';
                cb--;
            }
        }
        bitset<32>n(bn);
        return n.to_ulong();
    }
};