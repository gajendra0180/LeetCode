class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<int>&c){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0 || vis[i][j]==1)
            return;
        // cout<<i<<" "<<j<<endl;
        if(i+1>=grid.size()&&j+1>=grid[i].size() || (i+1<grid.size()&&j+1<grid[i].size()&&grid[i+1][j]==0&&grid[i][j+1]==0)|| (i+1<grid.size()&&j+1>=grid[i].size()&&grid[i+1][j]==0) || (j+1<grid[i].size()&&i+1>=grid.size()&&grid[i][j+1]==0))
        {
            c.push_back(i);
            c.push_back(j);
        }

        vis[i][j]=1;
        dfs(i-1,j,grid,vis,c);
        dfs(i,j-1,grid,vis,c);
        dfs(i+1,j,grid,vis,c);
        dfs(i,j+1,grid,vis,c);

    }
    
     vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        vector<vector<int>>vis;
         vector<vector<int>>res;
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[i].size();j++){
              temp.push_back(0);
            }
            vis.push_back(temp);
        }        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    // cout<<i<<" "<<j<<endl;
                    vector<int>times;
                    dfs(i,j,grid,vis,times);
                    // cout<<times.size()<<endl;
                    if(times.size()==2)
                    res.push_back({i,j,times[0],times[1]});
                }
            }
        }
        return res;
    }
};