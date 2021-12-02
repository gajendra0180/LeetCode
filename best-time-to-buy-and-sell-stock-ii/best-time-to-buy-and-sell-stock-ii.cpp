class Solution {
public:
    map<pair<int,int>,int> m;
    int profit(vector<int>&v,int buy,int i)
    {
        if(i==v.size())
            return 0;
        
        if(m.find({i,buy})!=m.end())
            return m[{i,buy}];
        
        if(buy)
        {
            return m[{i,buy}] = max(-v[i]+profit(v,0,i+1),profit(v,1,i+1));   
        }
        else
        {
            return m[{i,buy}] = max(v[i]+profit(v,1,i+1),profit(v,0,i+1));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        return profit(prices,1,0);
    }
};