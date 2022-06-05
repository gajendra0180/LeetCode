class Solution {
public:
    void dfs(int u,vector<vector<int>>&edges,map<int,int> &vis,map<int,vector<int>>&graph){
        for(auto v:graph[u]){
            if(!vis[v])
            {
                vis[v]=1;
                dfs(v,edges,vis,graph);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int,int>vis;
        map<int,vector<int>> graph;
        int components=0;
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
     
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                // cout<<i<<endl;
                components++;
                dfs(i,edges,vis,graph);
            }
        }
        return components;
    }
};