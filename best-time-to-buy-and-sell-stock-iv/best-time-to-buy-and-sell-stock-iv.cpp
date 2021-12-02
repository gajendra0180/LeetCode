class Solution {
public:
    struct HASH{
	size_t operator()(const pair<int,pair<int,int>> &x)const{
		return hash<int>()(x.first^(x.second.first)^(x.second.second));
	}
};
    unordered_map<pair<int,pair<int,int>>,int,HASH> m;
    int profit(vector<int>&v,int buy,int i,int k)
    {
        if(i==v.size()||k==0)
            return 0;
        
        if(m.find({i,{k,buy}})!=m.end())
            return  m[{i,{k,buy}}];
        
        if(buy)
        {
            return m[{i,{k,buy}}] = max(-v[i]+profit(v,0,i+1,k),profit(v,1,i+1,k));   
        }
        else
        {
            return m[{i,{k,buy}}] = max(v[i]+profit(v,1,i+1,k-1),profit(v,0,i+1,k));
        }
    }
    
    int maxProfit(int k,vector<int>& prices) {
        return profit(prices,1,0,k);
    }
};