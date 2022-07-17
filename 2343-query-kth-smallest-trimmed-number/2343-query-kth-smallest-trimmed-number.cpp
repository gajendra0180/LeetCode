class Solution {
public:
//        static bool csort(pair<string,int> s11, pair<string,int> s21)
// {
//        auto s1=s11.first;
//        auto s2=s21.first;
//        if(s1==s2){
//            return s11.second<s21.second;
//        }
//     if (s1.size() == s2.size()) {
//         return s1 < s2;
//     }
//     else {
//         return s1.size() < s2.size();
//     }
// }
    vector<int> smallestTrimmedNumbers(vector<string>& n, vector<vector<int>>& q) {
        vector<int>res;
        for(auto i:q){
            vector<pair<string,int>>temp;
            int index=0;
            for(auto j:n){
                temp.push_back({j.substr(j.size()-i[1]),index});
                index++;
            }
//             Note that custom sorting is not needed 
            sort(temp.begin(),temp.end());
            res.push_back(temp[i[0]-1].second);
        }
        return res;
    }
};