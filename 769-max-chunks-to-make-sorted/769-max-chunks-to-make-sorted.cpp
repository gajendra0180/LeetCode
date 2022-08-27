class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int start=0,minn=arr[0],maxx=arr[0],res=0;
        for(int i=0;i<arr.size();i++){
             minn=min(minn,arr[i]);
             maxx=max(maxx,arr[i]);
            // cout<<i<<" "<<minn<<" "<<start<<" "<<maxx<<endl;
            if(minn==start && maxx==i)
            {
                res++;
                start=i+1;
                if(start<arr.size())
                minn=arr[start],maxx=arr[start];
            }
        }
        return res;
    }
};

// 0 1 3 2
// 0 0 0 0
// 1 1 1 1
// 2 3 2 3
// 3 2 2 3
