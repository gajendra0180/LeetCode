class Solution {
public:
    void dfs(vector<int>&vis,map<int,vector<int>>&g,int &c,int u){
        vis[u]=1;
        for(auto v:g[u]){
            if(!vis[v])
            {
                c=c+1;
                dfs(vis,g,c,v);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>vis(n);
        map<int,vector<int>> m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            int times=0;
            if(!vis[i]){
                dfs(vis,m,times,i);
                // cout<<i<<" "<<times<<endl;
                res.push_back(times+1);
            }
        }
        // for(auto i:res)cout<<i<<" ";
        // cout<<endl;
        vector<long long>temp;long long s=0;
        for(int i=res.size()-1;i>=0;i--){
            s+=res[i];
            temp.push_back(s);
        }
        reverse(temp.begin(),temp.end());
        long long fres=0;
        // for(auto i:temp)cout<<i<<" ";
        for(int i=0;i<res.size()-1;i++){
            // cout<<res[i]<<" ";
            fres+=res[i]*temp[i+1];
        }
        return fres;
    }
};
