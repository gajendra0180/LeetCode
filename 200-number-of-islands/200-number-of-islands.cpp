class Solution {
public:

    int fres=0;
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,int c){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]=='0' || vis[i][j]==1)
            return;
        fres=max(c,fres);
        vis[i][j]=1;
        dfs(i-1,j,grid,vis,c+1);
        dfs(i,j-1,grid,vis,c+1);
        dfs(i+1,j,grid,vis,c+1);
        dfs(i,j+1,grid,vis,c+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis;
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[i].size();j++){
              temp.push_back(0);
            }
            vis.push_back(temp);
        }        
        int res=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(i,j,grid,vis,0);
                    res++;
                }
            }
        }
        cout<<fres<<endl;
        return res;
    }
};