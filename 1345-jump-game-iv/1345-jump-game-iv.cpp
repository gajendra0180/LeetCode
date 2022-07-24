class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        map<int,int>vis;
        vis[0]=1;
        while(dq.size()){
            int index=dq.front().first;
            int jumps=dq.front().second;
            dq.pop_front();
            if(index==arr.size()-1)
                return jumps;
            vis[index]=1;
            if(index+1<arr.size() && vis[index+1]!=1)
                dq.push_back({index+1,jumps+1});
            if(index-1>=0 && vis[index-1]!=1)
                dq.push_back({index-1,jumps+1});
            for(auto i:m[arr[index]]){
                if(!vis[i]){
                    vis[i]=1;
                    dq.push_back({i,jumps+1});
                }
            }
            m.erase(arr[index]);
        }
        return -1;       
    }
};