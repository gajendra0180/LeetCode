class Solution {
public:
    int partitionString(string s) {
        int res=1;
        map<char,int> m;
        for(auto i:s){
            if(m.find(i)!=m.end())
            {
                map<char,int>temp;
                temp[i]++;
                m=temp;
                res++;
            }else
                m[i]++;
        }
        return res;
    }
};