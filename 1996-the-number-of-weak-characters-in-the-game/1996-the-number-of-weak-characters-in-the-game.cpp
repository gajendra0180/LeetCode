class Solution {
public:
    static bool csort(vector<int> &a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),csort);
        vector<int>v;
        for(auto i:properties){
            v.push_back(i[1]);
        }
        // for(auto i:v)cout<<i<<" ";
        int mux=v.back(),res=0;
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]<mux)res++;
            mux=max(mux,v[i]);
        }
        return res;
    }
};