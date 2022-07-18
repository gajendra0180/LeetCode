class Solution {
public:

    vector<vector<int>>g1;
    void dfs(int i,int j,vector<vector<int>>&grid2,vector<vector<int>>&vis,int &c){
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[i].size() || grid2[i][j]==0 || vis[i][j]==1)
            return;
        vis[i][j]=1;
        
        if(g1[i][j]!=1)
            c=0;
        
        dfs(i-1,j,grid2,vis,c);
        dfs(i,j-1,grid2,vis,c);
        dfs(i+1,j,grid2,vis,c);
        dfs(i,j+1,grid2,vis,c);
    }
    
    int countSubIslands(vector<vector<int>>& grid1,vector<vector<int>>& grid2) {
        vector<vector<int>>vis;
        g1=grid1;
        for(int i=0;i<grid2.size();i++){
            vector<int>temp;
            for(int j=0;j<grid2[i].size();j++){
              temp.push_back(0);
            }
            vis.push_back(temp);
        }        
        int res=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){
                if(grid2[i][j]==1 && vis[i][j]==0)
                {
                    int times=1;
                    dfs(i,j,grid2,vis,times);
                    res+=times;
                }
            }
        }
        return res;
    }
};