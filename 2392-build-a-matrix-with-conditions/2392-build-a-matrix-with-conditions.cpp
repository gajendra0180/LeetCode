class Solution {
public:
    bool checkCycle(int u,map<int,vector<int>>&graph,map<int,int>&vis,map<int,int>&dfsVis){
        vis[u]=1;
        dfsVis[u]=1;
        for(auto v:graph[u]){
            if(!vis[v]){
                if(checkCycle(v,graph,vis,dfsVis))return true;
            }else if(dfsVis[v])
                return true;
        }
        dfsVis[u]=0;
        return false;
    }
    bool isCycle(map<int,vector<int>>graph,int k){
        map<int,int>vis,dfsVis;
        for(int i=1;i<=k;i++){
            if(!vis[i])
               if(checkCycle(i,graph,vis,dfsVis))return true;
        }
        return false;
    }
    void dfs(int u,map<int,vector<int>>&graph,map<int,int>&vis,vector<int>&res){
        for(auto v:graph[u]){
            if(!vis[v])
            {
                vis[v]=1;
                dfs(v,graph,vis,res);
            }
        }
        res.push_back(u);
    }   
    vector<int> topa(map<int,vector<int>>&graph,int k,map<int,int>vis){
        vector<int>res;
        for(int i=1;i<=k;i++){
            if(!vis[i]){
                vis[i]=1;
                dfs(i,graph,vis,res);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        map<int,vector<int>>graph;
        for(auto i:rowConditions){
            graph[i[0]].push_back(i[1]);
        }  
        // Print Graph
        // for(auto i:graph){
        //     cout<<i.first<<" @ ";
        //     for(auto j:i.second)cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<isCycle(graph,k)<<" This is cycle "<<endl;
        if(isCycle(graph,k))return {};
        map<int,int>vis2;
        vector<int> rs= topa(graph,k,vis2);
        map<int,vector<int>>graph1;
        map<int,int>vis1;      
        for(auto i:colConditions){
            graph1[i[0]].push_back(i[1]);
        }
        if(isCycle(graph1,k))return {};
    
        vector<int>cs= topa(graph1,k,vis1);
//         print order of elements
        // for(auto i:rs)cout<<i<<" ";
        // cout<<endl;
        // for(auto j:cs)cout<<j<<" ";
        // cout<<endl;
        map<int,int> cp,rp;
        for(int i=0;i<cs.size();i++){
            cp[cs[i]]=i;
        }
        for(int i=0;i<rs.size();i++){
            rp[rs[i]]=i;
        }
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            vector<int>temp;
            for(int j=0;j<k;j++){
                temp.push_back(0);
            }
            res.push_back(temp);
        }
        for(auto i:rs){
            int cop=cp[i];
            res[rp[i]][cop]=i;
        }
        return res;
    }
};