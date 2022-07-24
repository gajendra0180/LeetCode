class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<string>v;
        for(auto i:candidates){
            bitset<32>b(i);
            v.push_back(b.to_string());
        }
        int res=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int j=0;j<v.size();j++){
                if(v[j][i]=='1')
                    c++;
            }
            res=max(res,c);
        }
        return res;
    }
};