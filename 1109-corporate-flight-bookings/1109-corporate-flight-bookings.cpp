class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        map<int,int> m;
        for(auto i:bookings){
            m[i[0]]+=i[2];
            m[i[1]+1]-=i[2];
        }
        // for(auto i:m)cout<<i.first<<" "<<i.second<<endl;
        int res=0;vector<int>r;
        for(int i=1;i<=n;i++){
            res+=m[i];
            r.push_back(res);
        }
        return r;
    }
}; 