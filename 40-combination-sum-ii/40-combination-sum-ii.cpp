class Solution {
public:
     vector<vector<int>>res;
    // map<vector<int>,int>res;
    void get(vector<int>&v,int t,int i,int sum,vector<int>tres){
        
        if(i>=v.size())
            return;
        
        if(sum+v[i]==t){
            tres.push_back(v[i]);
            res.push_back(tres);
            // res[tres]=1;
            return;
        }
        
        if(sum+v[i]<t){
            //nhi liya 
            int temp=i;
            while(temp<v.size()&&v[temp]==v[i])
                temp++;
            get(v,t,temp,sum,tres);
            //liya
            tres.push_back(v[i]);
            sum+=v[i];
            get(v,t,i+1,sum,tres);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        get(v,target,0,0,{});
        vector<vector<int>>fres;
        // for(auto i:res)
            // fres.push_back(i.first);
        return res;
    }
};