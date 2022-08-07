class Solution {
public:
    void dfs(int u,map<int,vector<int>>&g,map<int,int>&vis,map<int,int>&rt){
        for(auto v:g[u]){
            if(!vis[v]&&rt.find(v)==rt.end()){
                vis[v]=1;
                dfs(v,g,vis,rt);
            }        
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        map<int,int>vis;
        map<int,vector<int>> graph;
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
        vis[0]=1;
        map<int,int>rt;
        for(auto i:restricted)rt[i]=1;
        dfs(0,graph,vis,rt);
        int res=0;
        for(auto i:vis){
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.second==1)res++;
        }
        return res;
    }
};