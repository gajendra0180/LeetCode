class Solution {
public:
    vector<vector<int>>res;int k_limit;
    void get(int n,int t,int sum,vector<int>tres,int size){
        
        if(n==10 || size>k_limit)
            return;
        
        if(sum+n==t && size==k_limit-1){
            tres.push_back(n);
            res.push_back(tres);
            return;
        }
        
        if(sum+n<t){
            //nhi liya 
            get(n+1,t,sum,tres,size);
            //liya
            tres.push_back(n);
            sum+=n;
            get(n+1,t,sum,tres,size+1);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        k_limit=k;
        get(1,n,0,{},0);
        return res;
    }
};