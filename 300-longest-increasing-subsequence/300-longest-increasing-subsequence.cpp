class Solution {
public:
    int dp[2501][2501];
    int lcs(vector<int> &a,vector<int>&b,int x,int y){
        if(x<0 || y<0)
            return 0;
        
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        if(a[x]==b[y])
            return  dp[x][y] = 1+lcs(a,b,x-1,y-1);
        else
            return dp[x][y] = max(lcs(a,b,x-1,y),lcs(a,b,x,y-1));
    }
    
    int lengthOfLIS(vector<int>& nums) {
        map<int,int> m;
            for(auto i:nums)m[i]=1;
        vector<int>b;
        for(auto i:m)b.push_back(i.first);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<b.size();j++){
                dp[i][j]=-1;
            }
        }
        return lcs(nums,b,nums.size()-1,b.size()-1);
        
    }
};