class Solution {
public:
  void dfs(int u,unordered_map<int,int>&vis,unordered_map<int,int>&m,map<int,vector<int>>&graph,int dis){
      for(auto v:graph[u]){
          if(!vis[v]){
                vis[v]=1;  
            if(v!=-1)
                m[v]=dis+1;
            dfs(v,vis,m,graph,dis+1);
          }
      }
  }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int,vector<int>>graph;
        for(int i=0;i<edges.size();i++)
            graph[i].push_back(edges[i]);
        unordered_map<int,int>vis1,vis2,m1,m2;
        dfs(node1,vis1,m1,graph,0);
        m1[node1]=0;
        dfs(node2,vis2,m2,graph,0);
        m2[node2]=0;
        int res=INT_MAX,res_i=-1;
        for(int i=0;i<edges.size();i++){
            if(m1.find(i)!=m1.end()&&m2.find(i)!=m2.end()){
                if(max(m1[i],m2[i])<res){
                    res=max(m1[i],m2[i]);
                    res_i=i;
                }
            }
        }
        return res_i;
    }
};