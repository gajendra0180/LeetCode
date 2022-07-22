class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        map<char,int>m1;        map<char,int>m2;
        for(auto i:s1)
            m1[i]++;
        int i=0,j=0;
        while(j<s1.size()){
            m2[s2[j]]++;
            j++;
        }
        if(m1==m2)return true;
        cout<<j<<endl;
        while(i<s2.size()&&j<s2.size()){
            // for(auto i:m2)cout<<i.first<<" "<<i.second<<endl;
            // cout<<endl;
            m2[s2[i]]--;
            if(m2[s2[i]]==0)
                m2.erase(s2[i]);
            m2[s2[j]]++;
            if(m1==m2)return true;
            j++;
            i++;
        }
        return false;
    }
};