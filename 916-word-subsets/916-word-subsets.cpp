class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int> m;
        for(auto i:words2){
            map<char,int>temp;
            for(auto j:i)temp[j]++;
            for(auto j:temp)m[j.first]=max(m[j.first],j.second);
        }
         vector<string>res;
        for(auto i:words1){
            map<char,int>temp;
            for(auto j:i){
                temp[j]++;
            }
            bool ans=true;
            for(auto i:m){
                if(i.second>temp[i.first]){
                    ans=false;
                    break;
                }
            }
            if(ans)
                res.push_back(i);
            
        }
       return res;
    }
};