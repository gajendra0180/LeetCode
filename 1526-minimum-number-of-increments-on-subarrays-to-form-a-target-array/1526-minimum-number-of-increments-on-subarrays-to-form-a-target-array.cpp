class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int minn=target[0],res=target[0];
        for(int i=1;i<target.size();i++){
            if(target[i]>minn){
                res+=target[i]-minn;
                minn=target[i];
            }
            else
            minn=min(minn,target[i]);
        }
        return res;
    }
};
