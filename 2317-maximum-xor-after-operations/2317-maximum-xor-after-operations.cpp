class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums){
            bitset<32>b(i);
            v.push_back(b.to_string());
        }
        string res;
        for(int i=0;i<32;i++){
            string p="0";
            for(int j=0;j<v.size();j++){
                if(v[j][i]=='1')
                    p[0]='1';
            }
        res+=p;
        }
        bitset<32>b(res);
        return b.to_ulong();
    }
};