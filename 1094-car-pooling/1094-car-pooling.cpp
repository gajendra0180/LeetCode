class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> m;
        for(int i=0;i<trips.size();i++){
            m[trips[i][1]]+=trips[i][0];
            m[trips[i][2]]-=trips[i][0];
        }
        int res=0;
        for(auto i:m){
            res+=i.second;
            if(res>capacity)
                return false;
            // cout<<i.first<<" "<<i.second<<endl;
        }
        return true;
    }
};