class Solution {
public:
        struct HASH{
	size_t operator()(const pair<int,int> &x)const{
		return hash<int>()(x.first^x.second);
	}
};
    unordered_map<pair<int,int>,int,HASH> m;
    bool can(int sum,vector<int>&v,int i,int req)
    {
        if(i>=v.size())
            return false;
        if(sum==req)
            return true;
        if(sum>req)
            return false;
        
        if(m.find({i,sum})!=m.end())
            return m[{i,sum}];
        
        return m[{i,sum}]=can(sum+v[i],v,i+1,req)||can(sum,v,i+1,req);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)sum+=i;
        if(sum%2==0)
        {
            sum/=2;
            if(can(0,nums   ,0,sum))
                return true;
        }            
        return false;
    }
};