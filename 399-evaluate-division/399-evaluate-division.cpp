class Solution {
public:
    double bfs(string src,string dtn,map<string,vector<pair<string,double>>>graph){
        deque<pair<string,double>>dq;
        dq.push_back({src,1});
        map<string,int>vis;
        vis[src]=1;
        while(dq.size()){
            auto pr=dq.front();
            dq.pop_front();
            if(pr.first==dtn){
                return pr.second;
            }
            for(auto vw:graph[pr.first]){
                string v=vw.first;
                double weight=vw.second;
                if(!vis[v])
                    vis[v]=1,dq.push_back({v,pr.second*weight});
            }
        }
        return -1;
    }
    
// a @b 2 
// b @a 0.5 c 3 
// c @b 0.333333 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>graph;
        int counter=0;
        for(auto i:equations){
            graph[i[0]].push_back({i[1],values[counter]});
            graph[i[1]].push_back({i[0],1.0/values[counter]});
            counter++;
        }
        // for(auto i:graph){
        //     cout<<i.first<<" @";
        //     for(auto j:i.second){
        //         cout<<j.first<<" "<<j.second<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<double>res;
        for(auto i:queries){
            if(graph.find(i[0])!=graph.end()&&graph.find(i[1])!=graph.end())
                res.push_back(bfs(i[0],i[1],graph));
            else
                res.push_back(-1);
        }
        return res;
    }
};