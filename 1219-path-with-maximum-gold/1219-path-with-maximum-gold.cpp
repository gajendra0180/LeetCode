class Solution {
public:
    int getGold(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
     
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==1)
            return 0;
        
        vis[i][j]=1;
        int a=grid[i][j]+getGold(grid,i+1,j,vis);
        int b=grid[i][j]+getGold(grid,i,j+1,vis);
        int c=grid[i][j]+getGold(grid,i-1,j,vis);
        int d=grid[i][j]+getGold(grid,i,j-1,vis);
        vis[i][j]=0;
        
        return max(a,max(b,max(c,d)));
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=INT_MIN;
        vector<vector<bool>>vis;
        
        for(int i=0;i<grid.size();i++){
            vector<bool> temp;
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(0);
            }
                vis.push_back(temp);
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res=max(res,getGold(grid,i,j,vis));
            }
        }
        return res;
    }
};