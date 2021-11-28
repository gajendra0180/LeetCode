class Solution {
public:
    void dfs(map<int,vector<int>>&g,bool &ans,bool mode,unordered_map<int,int>&viss,unordered_map<int,int>&know,int u)
    {
        if(mode==1)
        {
            // cout<<u<<endl;
            viss[u]=1;
            know[u]=1;
            for(auto v:g[u])
            {
                if(!viss[v])
                    dfs(g,ans,mode,viss,know,v);
            }
        }
        else
        {
            if(know[u]==1)
                ans=true;
            viss[u]=1;
            for(auto v:g[u])
            {
                if(!viss[v])
                    dfs(g,ans,mode,viss,know,v);
            }
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      unordered_map<int,int> know;
        know[0]=1;
        know[firstPerson]=1;
        set<int> time;
        for(auto i:meetings)
        {
            time.insert(i[2]);
        }
        vector<int> T;
        for(auto i:time)
            T.push_back(i);
        unordered_map<int,vector<pair<int,int>>> m;
        for(auto i:meetings)
            m[i[2]].push_back(make_pair(i[0],i[1]));
     
        for(auto i:T)
        {
            vector<pair<int,int>> pai=m[i];
            map<int,vector<int>> g;
            for(auto j:pai)
            {
                g[j.first].push_back(j.second);
                g[j.second].push_back(j.first);
            }
            set<int> temp;
            vector<int> tempp;
            for(auto j:pai)
            {
                tempp.push_back(j.first);
                tempp.push_back(j.second);
            }
            // for(auto j:temp)
            // {
            //     tempp.push_back(j);
            // }
            unordered_map<int,int> viss;
            for(auto j:tempp)
            {
                bool ans=false,ans2=false;
                int mode=0;
                if(!viss[j])
                {
                    unordered_map<int,int> vis;
                    dfs(g,ans,mode,viss,know,j);
                    if(ans)
                    {dfs(g,ans2,1,vis,know,j);
                    }
                }
            }
        }
        vector<int> result;
        for(auto i:know)
        {
            if(i.second==1)
            result.push_back(i.first);
        }                
        return result;
    }
};