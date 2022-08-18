class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto i:arr)m[i]++;
        vector<int>v;
        for(auto i:m)v.push_back(i.second);
        sort(v.begin(),v.end());
        int size=arr.size();
        int res=0;
        while(size>arr.size()/2){
            res++;
            size-=v.back();
            v.pop_back();
        }
        return res;
    }
};