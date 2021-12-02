class Solution {
public:
    map<pair<int,int>,int> m;
    int profit(vector<int>&v,int buy,int i,int run)
    {
        if(i==v.size()||run==0)
            return 0;
        
        if(m.find({i,buy})!=m.end())
            return m[{i,buy}];
        
        if(buy)
        {
            return m[{i,buy}] = max(-v[i]+profit(v,0,i+1,1),profit(v,1,i+1,1));   
        }
        else
        {
            return m[{i,buy}] = max(v[i]+profit(v,0,i+1,0),profit(v,0,i+1,1));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        return profit(prices,1,0,1);
    }
};