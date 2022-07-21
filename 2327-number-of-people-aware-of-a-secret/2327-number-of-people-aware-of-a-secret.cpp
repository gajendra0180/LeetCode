class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> v(n+delay+forget);
        v[0]=1;
        for(int i=0;i<n;i++){
            if(v[i]>=1){
            for(int j=i+delay;j<i+forget;j++){
                    v[j]=(v[j]+v[i])%int(1e9 + 7);
                }
            }
        // for(auto i:v)
        //     cout<<i<<" ";
        // cout<<endl;     
        }
        int res=0;
        for(int i=n-1;i>=n-forget;i--){
            if(i<0)break;
            res=(res+v[i])%int(1e9+7);
        }
        return res;
    }
};

