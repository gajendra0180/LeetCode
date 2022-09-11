class Solution {
public:
    vector<int> ple(vector<int>&arr){
        vector<int> minn;
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            if(st.size()==0){
                minn.push_back(-1);
                st.push(i);
            }
            else
            {
                while(st.size() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.size())
                    minn.push_back(st.top());
                else
                    minn.push_back(-1);
                st.push(i);
            }
        }
        return minn;
    }
    vector<int> nle(vector<int>&arr){
        vector<int> maxx;
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.size()==0){
                st.push(i);
                maxx.push_back(arr.size());
            }
            else
            {
                while(st.size() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(st.size())
                    maxx.push_back(st.top());
                else
                    maxx.push_back(arr.size());
                st.push(i);
            }
        }
        reverse(maxx.begin(),maxx.end());
        return maxx;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int MOD=1e9+7;
        vector<int> minn = ple(arr);
        vector<int> maxx = nle(arr);
        int res=0;
        for(int i=0;i<arr.size();i++){
            long long rightMul=((i-minn[i])%MOD*(maxx[i]-i)%MOD)%MOD;
            long long a=(arr[i]%MOD*rightMul%MOD)%MOD;
            res=(res%MOD+a%MOD)%MOD;
        }
        return res;
    }
};