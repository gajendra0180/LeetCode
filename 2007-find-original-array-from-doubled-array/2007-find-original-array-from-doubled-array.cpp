class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> m;
        for(auto i:changed){
            m[i]++;
        }
        if(m[0]%2!=0)
            return {};
        vector<int>res(m[0]/2);
        sort(changed.begin(),changed.end());
        for(int i=changed.size()-1;i>=0;i--){
            if(changed[i]==0)
                continue;
            if(m[changed[i]]>0){
                if(changed[i]%2!=0)
                    return{};
                else
                {
                    if(m[changed[i]/2]>0)
                    {
                        m[changed[i]]--;
                        res.push_back(changed[i]/2);
                        m[changed[i]/2]--;
                    }
                    else
                        return {};
                }
            }
            else{
                continue;
//                 This means it has been visited already by double
            }
        }
            return res;
    }
};