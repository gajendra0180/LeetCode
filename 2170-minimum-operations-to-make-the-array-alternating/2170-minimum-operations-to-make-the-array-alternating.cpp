class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> even;  
        map<int,int> odd;
        for(int i=0;i<nums.size();i+=2)
            even[nums[i]]++;
        for(int i=1;i<nums.size();i+=2)
            odd[nums[i]]++;
        int mfe=0,mf=0,mfo=0,mff=0;
        for(auto i:even){
            if(i.second>mf){
                mf=i.second;
                mfe=i.first;}
        }
        for(auto i:odd){
            if(i.second>mff)
            {
                mff=i.second;
                mfo=i.first;
            }
        }
        if(mfe!=mfo){
            int res=0;
            for(auto i:even){
                if(i.first!=mfe)
                    res+=i.second;
            }
            for(auto i:odd){
                if(i.first!=mfo)
                    res+=i.second;
            }
            return res;
        }
        else
        {
            int res=0;
            if(mf>mff){
                map<int,int>oddd=odd;
                oddd.erase(mfo);
                int mff=0,mfo=0;
            for(auto i:oddd){
                if(i.second>mff)
                {
                    mff=i.second;
                    mfo=i.first;
                }
            }
                 for(auto i:even){
                if(i.first!=mfe)
                    res+=i.second;
            }
            for(auto i:odd){
                if(i.first!=mfo)
                    res+=i.second;
            }
                return res;
                
            }
            else
            {
                map<int,int>evv=even;
                evv.erase(mfe);
                int mf=0,mfe=0;
                for(auto i:evv){
                    if(i.second>mf){
                        mf=i.second;
                        mfe=i.first;
                    }
                }
                 for(auto i:even){
                if(i.first!=mfe)
                    res+=i.second;
            }
            for(auto i:odd){
                if(i.first!=mfo)
                    res+=i.second;
            }
                return res;
                
            }
        }
        return 0;
    }
};