class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++)v.push_back(make_pair(arr[i],i));
        vector<pair<int,int>>Arr=v;
        sort(v.begin(),v.end());
         auto start=v[0],minn=Arr[0],maxx=Arr[0];
        int res=0;
        for(int i=0;i<arr.size();i++){
            // cout<<i<<endl;
             minn=min(minn,Arr[i]);
             maxx=max(maxx,Arr[i]);
            if(minn==start && maxx==v[i])
                res++;
        }
        return res;
    }
};
// [1,1,0,0,1]
// 1,0  1,1  0,2  0,3  1,4 -> Arr
// 0,2  0,3  1,0  1,1  1,4  -> v
// 1,0 1,0
// 1,0 1,1
// 0,2 1,1
//
