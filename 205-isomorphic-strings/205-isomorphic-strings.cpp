class Solution {
public:
    vector<int> get(string s){
        int counter=0;map<char,int>m;
        vector<int>v;
        for(auto i:s){
            if(m.find(i)!=m.end())
            {
                v.push_back(m[i]);
            }
            else
            {
                m[i]=counter;
                v.push_back(counter);
                counter++;
            }
        }
        return v;
    }
    bool isIsomorphic(string s, string t) {
        vector<int> a= get(s);
        vector<int> b= get(t);
        return a==b;
    }
};