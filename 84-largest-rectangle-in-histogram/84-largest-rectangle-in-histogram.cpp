class Solution {
public:
    vector<pair<int,int>> nsr(vector<int>v){
        stack<pair<int,int>>s;
        vector<pair<int,int>>res;
        for(int i=v.size()-1;i>=0;i--){
            if(s.size()==0){
                s.push({v[i],i});
                res.push_back({-1,v.size()});
            }
            else
            {
                while(s.size()){
                    if(s.top().first<v[i]){
                        res.push_back(s.top());
                        break;
                    }
                    else
                        s.pop();
                }
                if(s.size()==0)
                    res.push_back({-1,v.size()});
                s.push({v[i],i});
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<pair<int,int>> nsl(vector<int>v){
        stack<pair<int,int>>s;
        vector<pair<int,int>>res;
        for(int i=0;i<v.size();i++){
            if(s.size()==0){
                s.push({v[i],i});
                res.push_back({-1,-1});
            }
            else
            {
                while(s.size()){
                    if(s.top().first<v[i]){
                        res.push_back(s.top());
                        break;
                    }
                    else
                        s.pop();
                }
                if(s.size()==0)
                    res.push_back({-1,-1});
                s.push({v[i],i});
            }
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> nextSmallerRight=nsr(heights);
        vector<pair<int,int>> nextSmallerLeft=nsl(heights);
        // for(auto i:nextSmallerRight){
        //     cout<<i.first<<"@"<<i.second<<" ";
        // }
        // cout<<endl;
        // for(auto i:nextSmallerLeft){
        //     cout<<i.first<<"@"<<i.second<<" ";
        // }
        // cout<<endl;
        int res=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int sil=nextSmallerLeft[i].second+1;
            int sir=nextSmallerRight[i].second-1;
            res=max(res,(sir-sil+1)*heights[i]);
            // cout<<res<<" "<<sil<<" "<<sir<<" "<<i<<endl;
            }
        return res;
    }
};