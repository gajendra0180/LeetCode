class Solution {
public:
    int minSwaps(vector<int>& v) {
        int c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==1)
                c++;
        }
        int i=0,z=0,minn=INT_MAX;
        while(i<c){
            if(v[i]==0)
                z++;
            
            i++;
        }
        if(c<=1)return 0;
        minn=z;
        for(int j=i;j<v.size();j++){
            if(v[j]==0)
                z++;
            if(v[j-c]==0)
            z--;
            minn=min(z,minn);
        }
        return minn;
    }
};