class Solution {
public:

    int fres=0;
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int &c){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0 || vis[i][j]==1)
            return;
        // fres=max(c,fres);
        // cout<<c<<endl;
        vis[i][j]=1;
        c=c+1;
        dfs(i-1,j,grid,vis,c);
        dfs(i,j-1,grid,vis,c);
        dfs(i+1,j,grid,vis,c);
        dfs(i,j+1,grid,vis,c);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
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
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    // cout<<"Times"<<endl;
                    int times=0;
                    dfs(i,j,grid,vis,times);
                    // cout<<times<<endl;
                    fres=max(fres,times);
                }
            }
        }
        return fres;
    }
};