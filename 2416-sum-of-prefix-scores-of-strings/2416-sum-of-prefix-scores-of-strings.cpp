class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<size_t,int> pref;
        hash<string> hash_fn;
        vector<vector<size_t>> v;
        for(auto i:words){
            string s;
            vector<size_t>temp;
            for(auto j:i){
                s.push_back(j);
                auto hf=hash_fn(s);
                pref[hf]++;
                // temp.push_back(hf);
                temp.push_back(hf);
            }
            v.push_back(temp);
        }
        vector<int>r;
        for(auto i:v){
            int res=0;
            for(auto j:i){
                res+=pref[j];
            }
            r.push_back(res);
        }
        return r;
    }
};