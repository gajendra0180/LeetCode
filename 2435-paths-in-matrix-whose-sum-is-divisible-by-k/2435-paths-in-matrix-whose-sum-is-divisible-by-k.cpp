class Solution {
public:
    int MOD=1e9+7;
    vector<vector<vector<int>>>dp;
    int get(vector<vector<int>>&grid,int k,int i,int j,int sum){
        if(i>=grid.size() || j>=grid[0].size())
            return 0;
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            if((sum+grid[i][j])%k==0){
                return 1;
            }
            else
                return 0;
        }
        if(dp[i][j][sum]!=-1)
            return dp[i][j][sum];
        
        int sum1=0,sum2=0;
        if(i+1>=grid.size())
            sum1=0;
        else
        {
            sum1=get(grid,k,i+1,j,((sum%MOD+grid[i][j]%MOD)%MOD)%k);
        }
        
        if(j+1>=grid[0].size())
            sum2=0;
        else
        {
            sum2=get(grid,k,i,j+1,((sum%MOD+grid[i][j]%MOD)%MOD)%k);
        }
        return dp[i][j][sum] = (sum1%MOD+sum2%MOD)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        for(auto i:grid){
            vector<vector<int>>temp;
            for(auto j:i){
                vector<int>tempp;
                for(int k=0;k<51;k++){
                    tempp.push_back(-1);
                }
                temp.push_back(tempp);
            }
            dp.push_back(temp);
        }
        return get(grid,k,0,0,0);
    }
};