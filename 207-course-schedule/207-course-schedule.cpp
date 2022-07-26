class Solution {
public:
    bool hasCycle(int u,map<int,vector<int>>&g,map<int,int>&vis,map<int,int>dfsVis){
        vis[u]=1;
        dfsVis[u]=1;
        for(auto v:g[u]){
            if(!vis[v]){
                if(hasCycle(v,g,vis,dfsVis))
                    return true;
            }else if(dfsVis[v]==1)
                return true;
        }
        dfsVis[u]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       map<int,vector<int>>g;
        for(auto i:prerequisites)
            g[i[1]].push_back(i[0]);
        map<int,int> vis,dfsVis;        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(hasCycle(i,g,vis,dfsVis))
                    return false;
            }
        }
        return true;
    }
};