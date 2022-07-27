class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& v) {
            map<int, vector<int>> g;
            map<int, int> indegree;
        for(auto i:v)
        {
            indegree[i[0]]++;
            g[i[1]].push_back(i[0]);
        }
        vector<int> res;
        int vis_count = 0;
        deque<int> dq;
        for (int i = 0; i <numCourses; i++)
            if (indegree[i] == 0)
                dq.push_back(i);
        while (dq.size())
        {
            auto u = dq.front();
            dq.pop_front();
            cout<<u;
            res.push_back(u);
            vis_count++;
            for (auto v : g[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    dq.push_back(v);
            }
        }
        if(vis_count!=numCourses)
            return {};
        return res;
    }
};