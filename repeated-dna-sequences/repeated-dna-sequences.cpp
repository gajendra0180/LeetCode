class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    
        map<size_t,int> m;
        hash<string> hash_fn;
        vector<string> v;
        set<string> st;
        for(int i=0;i<int(s.size())-9;i++)
        {
            string temp=s.substr(i,10);
            m[hash_fn(temp)]++;
            if(m[hash_fn(temp)]>1)
                st.insert(temp);
        }
        for(auto i:st)
        {
            v.push_back(i);
        }
        return v;
    }
};