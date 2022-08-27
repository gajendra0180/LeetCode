class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0;
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            v.push_back(arr[i]);
            vector<int>temp=v;
            sort(v.begin(),v.end());
            bool is=true;
            for(int j=0;j<v.size();j++){
                if(v[j]!=j)
                {is=false;break;}
            }
            if(is)
                res++;
            v=temp;
        }
        return res;
    }
};
    