class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& n, vector<vector<int>>& q) {
        vector<int>res;
        for(auto i:q){
            vector<pair<string,int>>temp;
            
            for(int j=0;j<n.size();j++)
                temp.push_back({n[j].substr(n[j].size()-i[1]),j});
            
            sort(temp.begin(),temp.end());
            res.push_back(temp[i[0]-1].second);
        }
        return res;
    }
};